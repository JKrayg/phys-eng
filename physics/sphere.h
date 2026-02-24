#pragma once

#include "shape.h"

class Sphere : public Shape {
public:

	double radius;
	Sphere(
		std::string const shape_type = "Sphere",
		double radius = 1.0) : Shape(shape_type), radius(radius) {}

	double volume() {}


};