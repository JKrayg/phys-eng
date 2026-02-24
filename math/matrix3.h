#pragma once

#include <array>
#include <string>
#include "vector3.h"


struct Matrix3 {

public:
	std::array<double, 9> matrix;

	Matrix3(std::array<double, 9>& m) : matrix(m){}

	std::string to_string();

	Vector3 operator*(const Vector3& vec) const;
	Matrix3 operator*(const Matrix3& m) const;
	Matrix3 operator/(const double s) const;
	Matrix3 transpose() const;
	Matrix3 inverse() const;
	double determinant() const;
};