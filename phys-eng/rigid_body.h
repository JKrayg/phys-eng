#pragma once

#include <memory>
#include "vector3.h"
#include "constants.h"
#include "entity.h"
#include "shape.h"
#include "mesh.h"
#include "shader.h"
#include "sphere.h"

struct RigidBody : public Entity {

	std::unique_ptr<Shape> shape;

	RigidBody(
		std::unique_ptr<Shape> shape = std::make_unique<Sphere>(),
		std::string name = "Earth",
		double mass = 0,
		Vector3 position = Vector3(0, 0, 0),
		Vector3 velocity = Vector3(0, 0, 0),
		Vector3 acceleration = Vector3(0, 0, 0),
		Vector3 net_force = Vector3(0, 0, 0),
		Quaternion orientation = (0, 0, 0, 0),
		Vector3 angular_velocity = Vector3(0, 0, 0))
		: shape(std::move(shape)),
		Entity(name, mass, position,
		velocity, acceleration,
		net_force, orientation,
		angular_velocity) {}

	std::string to_string();
};
