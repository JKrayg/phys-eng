#include <iostream>
#include <typeinfo>
#include <ctime>
#include <chrono>
#include <thread>

// GLAD loads OpenGL function pointers
#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>

// GLFW for window creation and input handling
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

// Linmath for matrix math
#include "linmath.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

// ================= Vertex Structure ==================

// Define a vertex: position (vec2) and color (vec3)
typedef struct Vertex
{
    vec2 pos;  // 2D position (x, y)
    vec3 col;  // RGB color
} Vertex;

// ================= Vertex Data =======================

// Triangle vertices: position and color
static const Vertex vertices[3] =
{
    { { -0.6f, -0.4f }, { 1.f, 0.f, 0.f } }, // red vertex
    { {  0.6f, -0.4f }, { 0.f, 1.f, 0.f } }, // green vertex
    { {   0.f,  0.6f }, { 0.f, 0.f, 1.f } }  // blue vertex
};

// ================= GLSL Shaders ======================

// Vertex shader: transforms vertex positions and passes color to fragment shader
static const char* vertex_shader_text =
// variables
"#version 330\n"
"uniform mat4 MVP;\n"      // Model-View-Projection matrix
"in vec3 vCol;\n"          // Vertex color input
"in vec2 vPos;\n"          // Vertex position input
"out vec3 color;\n"        // Output color to fragment shader
// main function
"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n" // Transform vertex to clip space
"    color = vCol;\n"                             // Pass color along
"}\n";

// Fragment shader: colors each pixel of the triangle
static const char* fragment_shader_text =
// variables
"#version 330\n"
"in vec3 color;\n"       // Interpolated color from vertex shader
"out vec4 fragment;\n"   // Final color output
// main function
"void main()\n"
"{\n"
"    fragment = vec4(color, 1.0);\n"  // Set pixel color with alpha = 1
"}\n";

// ================= GLFW Callbacks ====================

// Error callback: prints GLFW errors to stderr
static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

// Key callback: closes window when Escape is pressed
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

// ================= Main Function =====================
int main(void)
{
    // Set error callback before initializing GLFW
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())   // Initialize GLFW library
        exit(EXIT_FAILURE);

    // Request OpenGL 3.3 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window
    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Triangle", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Set key callback
    glfwSetKeyCallback(window, key_callback);

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    // Load OpenGL function pointers with GLAD
    gladLoadGL();

    // Enable V-Sync (limit to monitor refresh rate)
    glfwSwapInterval(1);

    // ================= Create Vertex Buffer =================

    GLuint vertex_buffer;
    glGenBuffers(1, &vertex_buffer);                               // Generate buffer ID
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);                  // Bind it as a vertex buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Upload vertex data

    // ================= Compile Shaders =====================

    const GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER); // Create vertex shader
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);   // Attach GLSL source
    glCompileShader(vertex_shader);                                 // Compile it

    const GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER); // Create fragment shader
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);   // Attach GLSL source
    glCompileShader(fragment_shader);                                   // Compile it

    // ================= Link Shader Program =================

    const GLuint program = glCreateProgram();          // Create shader program
    glAttachShader(program, vertex_shader);           // Attach vertex shader
    glAttachShader(program, fragment_shader);         // Attach fragment shader
    glLinkProgram(program);                           // Link shaders into program

    // Get locations of shader inputs
    const GLint mvp_location = glGetUniformLocation(program, "MVP"); // MVP uniform
    const GLint vpos_location = glGetAttribLocation(program, "vPos"); // Position attribute
    const GLint vcol_location = glGetAttribLocation(program, "vCol"); // Color attribute

    // ================= Vertex Array Object =================

    GLuint vertex_array;
    glGenVertexArrays(1, &vertex_array);   // Generate VAO ID
    glBindVertexArray(vertex_array);       // Bind VAO

    // Set up position attribute
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
        sizeof(Vertex), (void*)offsetof(Vertex, pos));

    // Set up color attribute
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
        sizeof(Vertex), (void*)offsetof(Vertex, col));

    // ================= Main Loop ==========================

    while (!glfwWindowShouldClose(window))
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);      // Get window size
        const float ratio = width / (float)height;           // Aspect ratio

        glViewport(0, 0, width, height);                     // Set viewport
        glClear(GL_COLOR_BUFFER_BIT);                        // Clear screen

        // ================= Matrix Setup =====================

        mat4x4 m, p, mvp;
        mat4x4_identity(m);                                  // Identity model matrix
        mat4x4_rotate_Z(m, m, (float)glfwGetTime());         // Rotate model around Z over time
        mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f); // Orthographic projection
        mat4x4_mul(mvp, p, m);                               // MVP = Projection * Model

        // ================= Draw Triangle ====================

        glUseProgram(program);                                // Use shader program
        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*)&mvp); // Set MVP uniform
        glBindVertexArray(vertex_array);                      // Bind VAO
        glDrawArrays(GL_TRIANGLES, 0, 3);                     // Draw 3 vertices (triangle)

        glfwSwapBuffers(window);  // Swap front/back buffers
        glfwPollEvents();         // Poll for window events (keyboard/mouse)
    }

    // ================= Cleanup ===========================

    glfwDestroyWindow(window); // Destroy window
    glfwTerminate();           // Terminate GLFW
    exit(EXIT_SUCCESS);
}
