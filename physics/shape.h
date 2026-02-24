#pragma once

#include <string>

class Shape {
public:

	std::string const shape_type;

	Shape(std::string const shape_type) : shape_type(shape_type) {}
	virtual ~Shape() {}
};