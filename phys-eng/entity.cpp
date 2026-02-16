
#include "entity.h"

std::string Entity::to_string() const {
	return "Name: " + name
		+ "\nMass: " + std::to_string(mass)
		+ "\nPosition: " + position.to_string()
		+ "\nVelocity: " + velocity.to_string()
		+ "\nAcceleration: " + acceleration.to_string()
		+ "\nForce: " + net_force.to_string()
		+ "\nAngular velocity: " + angular_velocity.to_string()
		+ "\nOrientation: " + orientation.to_string(); 
}