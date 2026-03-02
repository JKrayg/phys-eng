
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
#include <random>

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


    std::array<double, 9> arr1 = {1, 2, 3, 2, 5, 6, 3, 6, 9};
    std::array<double, 9> arr2 = {1, 4, 7, 2, 1, 8, 3, 6, 1};

    Vector3 vec1 = Vector3(8, 1, 3);
    Vector3 vec2 = Vector3(1, 2, 3);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1000000.0, 1000000.0);

    std::array<double, 9> randm1 = {
        dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen)
    };

    std::array<double, 9> randm2 = {
        dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen),
        dis(gen), dis(gen), dis(gen)
    };

    std::array<double, 9> we = { 2, 0, 0, 0, 3, 0, 0, 0, 4 };

    Matrix3 m1 = Matrix3(randm1);
    Matrix3 m2 = Matrix3(randm2);

    Vector3 vmmul = m1 * vec1;
    Matrix3 mmul = m1 * m2;
    Matrix3 vvmul = vec1 * vec2;
    Matrix3 skew = vec1.skew();
    Matrix3 tpose = mmul.transpose();
    double det = m1.determinant();

    Vector3 solv = m1.solve(vec1);
    Vector3 proj = vec1.project_onto(vec2);
    Vector3 refl = vec1.reflect(vec2.normalize());

    Matrix3 inv = m2.inverse();
    Matrix3 id = m2.identity();
    Matrix3 zero = m2.zeros();
    Matrix3 dia = m2.diagonal(2, 3, 4);

    Matrix3 e = Matrix3().diagonal(64, 64, 64);
        



    std::cout 
        << m1.to_string()
        << "\n\n" << m2.to_string()
        << "\n\n" << mmul.to_string()
        << "\n\n" << tpose.to_string() 
        << "\n\n" << det 
        << "\n\n" << inv.to_string()
        << "\n\n" << (m2 * inv).to_string()
        //<< "\n\n" << vvmul.to_string() 
        << "\n\n" << skew.to_string() 
        /*<< "\n\n" << solv.to_string() 
        << "\n\n" << proj.to_string() 
        << "\n\n" << refl.to_string() */
        << "\n\n" << vec1.clamp_length(0.5).to_string() 
        << "\n\n" << id.to_string() 
        << "\n\n" << zero.to_string() 
        << "\n\n" << e.to_string() 
        << "\n\n" << m1.is_invertible() 
        << "\n\n" << m2.is_invertible() 
        << "\n\n" << m1.is_symmetric() 
        << "\n\n" << m2.is_symmetric() 
        << "\n\n" << m2.trace() << std::endl;

    return 0;
};