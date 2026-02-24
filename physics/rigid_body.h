#pragma once

#include <memory>
#include "../math/vector3.h"
#include "../math/quaternion.h"
#include "../math/constants.h"
#include "shape.h"
#include "sphere.h"

struct RigidBody {

	std::unique_ptr<Shape> shape;
	std::string name;
	double mass;
	Vector3 position;
	Vector3 velocity;
	Vector3 acceleration;
	Vector3 net_force;
	Vector3 angular_velocity;
	Quaternion orientation;

	RigidBody(
		std::unique_ptr<Shape> shape = std::make_unique<Sphere>(),
		std::string name = "Earth",
		double mass = 0,
		Vector3 position = Vector3(0, 0, 0),
		Vector3 velocity = Vector3(0, 0, 0),
		Vector3 acceleration = Vector3(0, 0, 0),
		Vector3 net_force = Vector3(0, 0, 0),
		Vector3 angular_velocity = Vector3(0, 0, 0),
		Quaternion orientation = (1, 0, 0, 0))
		: shape(std::move(shape)), name(name), mass(mass),
			position(position), velocity(velocity),
			acceleration(acceleration), net_force(net_force),
			orientation(orientation), angular_velocity(angular_velocity) {}

	std::string to_string() const;
};
