
#include <iostream>
#include <typeinfo>
#include <ctime>
#include <chrono>
#include <thread>
#include <string>
#include "../engine_lib/phys.h"
#include "../engine_lib/constants.h"
#include "../engine_lib/rigid_body.h"
#include "../engine_lib/vector3.h"
#include "../engine_lib/shader.h"
#include "../engine_lib/shape.h"
#include "../engine_lib/mesh.h"
#include "../engine_lib/time.h"

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

    bool running = true;

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
    return 0;
};