
#include <iostream>
#include "math.h"
#include "constants.h"
#include "rigid_body.h"
#include "vector3.h"
#include "shader.h"
#include "shape.h"
#include "mesh.h"


int main(void) {
    Math math;

    RigidBody earth = RigidBody();
    double energy = math.rest_energy(earth.mass);

    Vector3 vec1 = Vector3(1.0, 2.0, 3.0);
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

    /*Vector3& subt_update = vec1 -= vec2;
    Vector3& add_update = vec1 += vec2;
    Vector3& mul_scl_2_update = vec1 *= 2.0;
    Vector3& div_scl_2_update = vec1 /= 2.0;
    Vector3& cross_update = vec1.cross_assign(vec2);
    Vector3& inverted_update = vec1.invert_assign();*/


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
    std::cout << "Length after normalize (vec1): " << normalized.length() << std::endl;


    return 0;
};