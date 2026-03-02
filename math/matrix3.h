#pragma once

#include <array>
#include <string>
#include "vector3.h"


struct Matrix3 {

public:
	std::array<double, 9> matrix;
	Matrix3(std::array<double, 9> m = {0, 0, 0, 0, 0, 0, 0, 0, 0}) : matrix(m) {};

	Matrix3 operator-(const Matrix3& m) const;
	Vector3 operator*(const Vector3& vec) const;
	Matrix3 operator*(const Matrix3& m) const;
	Matrix3 operator/(const double s) const;
	Matrix3& operator*=(const Matrix3& m);
	Matrix3& operator/=(const double& s);
	Matrix3 transpose() const;
	Matrix3 inverse() const;
	Matrix3 identity() const;
	Matrix3 zeros() const;
	Matrix3 diagonal(const double x, const double y, const double z) const;
	Vector3 solve(const Vector3& vec) const;
	double determinant() const;
	double trace() const;
	bool is_invertible() const;
	bool is_symmetric() const;
	std::string to_string();
};