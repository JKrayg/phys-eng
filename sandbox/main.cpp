
#include <iostream>
#include <typeinfo>
#include <ctime>
#include <chrono>
#include <thread>
#include <string>
#include <array>
#include "../physics/phys.h"
#include "../physics/rigid_body.h"
#include "../physics/shape.h"
#include "../math/constants.h"
#include "../math/vector3.h"
#include "../math/matrix3.h"
#include "../rendering/shader.h"
#include "../rendering/mesh.h"
#include "../core/time.h"

int main(void) {
    Phys math;
    RigidBody earth = RigidBody();
    double energy = math.rest_energy(earth.mass);

    earth.acceleration.x = 2.0;
    earth.acceleration.y = 5.0;
    earth.acceleration.z = 5.0;
    earth.velocity.x = 2.0;
    earth.velocity.y = 3.0;
    earth.velocity.z = 3.0;
    earth.position.x = 1.0;
    earth.position.y = 1.0;
    earth.position.z = 1.0;

    earth.mass = 1030.64574;
    earth.net_force = earth.acceleration * earth.mass;
    //std::cout << earth.net_force.to_string() << std::endl;

    Time t = Time();

    bool running = false;

    while (running) {

        t.update_time();
        while (t.accumulator >= Constants::TIME_STEP) {

            // physics
            std::string pod = earth.position.to_string();
            std::cout << pod << std::endl;
            math.update_position(earth);

            t.accumulator -= Constants::TIME_STEP;

        }

        double a = t.accumulator / Constants::TIME_STEP;
        std::this_thread::sleep_for(std::chrono::milliseconds(16));


    }

    // --------------------------------------------------------------


    std::array<double, 9> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<double, 9> arr2 = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    Vector3 vec1 = Vector3(1, 1, 1);
    Matrix3 m1 = Matrix3(arr1);
    Matrix3 m2 = Matrix3(arr2);

    Vector3 vmul = m1 * vec1;
    Matrix3 mmul = m1 * m2;

    std::cout << mmul.to_string() << std::endl;
    return 0;
};