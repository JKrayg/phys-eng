
#include "rigid_body.h"

std::string RigidBody::to_string() {
	return "Name: " + name
		+ "\nPosition: " + position.to_string()
		+ "\nMass: " + std::to_string(mass)
		+ "\nValocity: " + velocity.to_string(),
		+"\nAcceleration: " + acceleration.to_string(),
		+"\nForce: " + net_force.to_string();
}

