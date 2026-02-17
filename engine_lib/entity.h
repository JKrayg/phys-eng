#pragma once

#include "vector3.h"
#include "constants.h"
#include "quaternion.h"

class Entity {

public:
	std::string name;
	double mass;
	Vector3 position;
	Vector3 velocity;
	Vector3 acceleration;
	Vector3 net_force;
	Vector3 angular_velocity;
	Quaternion orientation;

	Entity(
		std::string name,
		double mass,
		Vector3 position,
		Vector3 velocity,
		Vector3 acceleration,
		Vector3 net_force,
		Quaternion orientation,
		Vector3 angular_velocity)
		: name(name), mass(mass), position(position),
		velocity(velocity), acceleration(acceleration),
		net_force(net_force), orientation(orientation),
		angular_velocity(angular_velocity) {}

	std::string to_string() const;
};