#pragma once
#include <string>

struct Quaternion {
	double w, x, y, z;
	Quaternion(double w = 1, double x = 0,
		double y = 0, double z = 0)
		: w(w), x(x), y(y), z(z) {}

	std::string to_string() const;
};