
#include <iostream>
#include <typeinfo>
#include <ctime>
#include <chrono>
#include <thread>
#include "physics.h"
#include "constants.h"
#include "rigid_body.h"
#include "vector3.h"
#include "shader.h"
#include "shape.h"
#include "mesh.h"
#include "time.h"


int main(void) {
    Physics math;

    RigidBody earth = RigidBody();
    double energy = math.rest_energy(earth.mass);

    Shape* s = earth.shape.get();
    Sphere* sh = dynamic_cast<Sphere*>(s);

    //std::cout << earth.to_string() << std::endl;

    // F = ma
    Vector3 acceleration = earth.acceleration;
    acceleration.x = 0;
    acceleration.y = 1.0;
    acceleration.z = 0;
    earth.velocity.x = 2.0;
    earth.velocity.y = 1.0;
    earth.velocity.z = 3.0;
    earth.position.x = 1.0;
    earth.position.y = 1.0;
    earth.position.z = 1.0;

    earth.mass = 100;
    earth.net_force = acceleration * earth.mass;

    /*std::cout << "Acceleration: " << acceleration.to_string() << std::endl;
    std::cout << "Mass: " << earth.mass << std::endl;
    std::cout << "Force: " << earth.net_force.to_string() << std::endl;*/

    Time t = Time();

    int frame = 0;
    bool running = true;

    while (running) {

        t.update_time();
        while (t.accumulator >= Constants::TIME_STEP) {

            // physics
            std::cout << earth.position.to_string() << std::endl;
            math.update_position(earth);



            t.accumulator -= Constants::TIME_STEP;

            /*std::cout << "Frame: " << frame << std::endl;
            std::cout << "delta_time: " << t.delta_time << std::endl;
            std::cout << "accumulator: " << t.accumulator << std::endl;*/

        }

        double a = t.accumulator / Constants::TIME_STEP;
        std::this_thread::sleep_for(std::chrono::milliseconds(16));


        frame += 1;
    }






    /*Vector3 vec1 = Vector3(1.0, 2.0, 3.0);
    Vector3 vec2 = Vector3(4.0, 5.0, 6.0);
    std::string vecs = vec1.to_string() + "\n" + vec2.to_string();

    Vector3 subt = vec1 - vec2;
    Vector3 add = vec1 + vec2;
    Vector3 mul_scl_2 = vec1 * 2.0;
    Vector3 div_scl_2 = vec1 / 2.0;
    Vector3 cross = vec1.cross(vec2);
    Vector3 inverted = vec1.inverted();
    Vector3 normalized = vec1.normalize();
    double dot = vec1.dot(vec2);

    Vector3& subt_update = vec1 -= vec2;
    Vector3& add_update = vec1 += vec2;
    Vector3& mul_scl_2_update = vec1 *= 2.0;
    Vector3& div_scl_2_update = vec1 /= 2.0;
    Vector3& cross_update = vec1.cross_assign(vec2);
    Vector3& inverted_update = vec1.invert_assign();


    std::cout << "Vecs: " << vecs << std::endl;
    std::cout << "Subtract: " << subt.to_string() << std::endl;
    std::cout << "Add: " << add.to_string() << std::endl;
    std::cout << "Mult by scalar (vec1 * 2): " << mul_scl_2.to_string() << std::endl;
    std::cout << "Div by scalar (vec1 / 2): " << div_scl_2.to_string() << std::endl;
    std::cout << "Dot prod: " << dot << std::endl;
    std::cout << "Cross prod: " << cross.to_string() << std::endl;
    std::cout << "Invert (vec1): " << inverted.to_string() << std::endl;
    std::cout << "Length before normalize (vec1): " << vec1.length() << std::endl;
    std::cout << "Normalized (vec1): " << normalized.to_string() << std::endl;
    std::cout << "Length after normalize (vec1): " << normalized.length() << std::endl;*/


    return 0;
};