
#include <string>
#include <iostream>
#include "matrix3.h"


Vector3 Matrix3::operator*(const Vector3& vec) const {
	return Vector3(
		matrix[0] * vec.x + matrix[1] * vec.y + matrix[2] * vec.z,
		matrix[3] * vec.x + matrix[4] * vec.y + matrix[5] * vec.z,
		matrix[6] * vec.x + matrix[7] * vec.y + matrix[8] * vec.z
	);
}


Matrix3 Matrix3::operator*(const Matrix3& m) const {
	std::array<double, 9> mmul = {
		matrix[0] * m.matrix[0] + matrix[1] * m.matrix[3] + matrix[2] * m.matrix[6],
		matrix[0] * m.matrix[1] + matrix[1] * m.matrix[4] + matrix[2] * m.matrix[7],
		matrix[0] * m.matrix[2] + matrix[1] * m.matrix[5] + matrix[2] * m.matrix[8],
		matrix[3] * m.matrix[0] + matrix[4] * m.matrix[3] + matrix[5] * m.matrix[6],
		matrix[3] * m.matrix[1] + matrix[4] * m.matrix[4] + matrix[5] * m.matrix[7],
		matrix[3] * m.matrix[2] + matrix[4] * m.matrix[5] + matrix[5] * m.matrix[8],
		matrix[6] * m.matrix[0] + matrix[7] * m.matrix[3] + matrix[8] * m.matrix[6],
		matrix[6] * m.matrix[1] + matrix[7] * m.matrix[4] + matrix[8] * m.matrix[7],
		matrix[6] * m.matrix[2] + matrix[7] * m.matrix[5] + matrix[8] * m.matrix[8]
	};

	return Matrix3(mmul);
}

Matrix3 Matrix3::operator/(const double s) const {
	std::array<double, 9> div = {
		matrix[0] / s, matrix[1] / s,
		matrix[2] / s, matrix[3] / s,
		matrix[4] / s, matrix[5] / s,
		matrix[6] / s, matrix[7] / s,
		matrix[8] / s
	};

	return Matrix3(div);
}

Matrix3 Matrix3::transpose() const {
	std::array<double, 9> tpose = {
		matrix[0], matrix[3], matrix[6],
		matrix[1], matrix[4], matrix[7],
		matrix[2], matrix[5], matrix[8]
	};
	return Matrix3(tpose);
}

Matrix3 Matrix3::inverse() const {
	std::array<double, 9> inv = {
		(matrix[4] * matrix[8] - matrix[5] * matrix[7]) * (((0 + 0) % 2 == 0) ? 1 : -1),
		(matrix[3] * matrix[8] - matrix[5] * matrix[6]) * (((0 + 1) % 2 == 0) ? 1 : -1),
		(matrix[3] * matrix[7] - matrix[4] * matrix[6]) * (((0 + 2) % 2 == 0) ? 1 : -1),
		(matrix[1] * matrix[8] - matrix[2] * matrix[7]) * (((1 + 0) % 2 == 0) ? 1 : -1),
		(matrix[0] * matrix[8] - matrix[2] * matrix[6]) * (((1 + 1) % 2 == 0) ? 1 : -1),
		(matrix[0] * matrix[7] - matrix[1] * matrix[6]) * (((1 + 2) % 2 == 0) ? 1 : -1),
		(matrix[1] * matrix[5] - matrix[2] * matrix[4]) * (((2 + 0) % 2 == 0) ? 1 : -1),
		(matrix[0] * matrix[5] - matrix[2] * matrix[3]) * (((2 + 1) % 2 == 0) ? 1 : -1),
		(matrix[0] * matrix[4] - matrix[1] * matrix[3]) * (((2 + 2) % 2 == 0) ? 1 : -1)
	};

	Matrix3 m = Matrix3(inv);

	return m.transpose() / this->determinant();
}

Vector3 Matrix3::solve(const Vector3& vec) const
{
	double det = this->determinant();

	if (std::abs(det) < 1e-8) {
		return Vector3(0, 0, 0);
	}
	else {
		return Vector3(
			((matrix[4] * matrix[8] - matrix[5] * matrix[7]) * vec.x +
				(matrix[2] * matrix[7] - matrix[1] * matrix[8]) * vec.y +
				(matrix[1] * matrix[5] - matrix[2] * matrix[4]) * vec.z) / det,
			((matrix[5] * matrix[6] - matrix[3] * matrix[8]) * vec.x +
				(matrix[0] * matrix[8] - matrix[2] * matrix[6]) * vec.y +
				(matrix[2] * matrix[3] - matrix[0] * matrix[5]) * vec.z) / det,
			((matrix[3] * matrix[7] - matrix[4] * matrix[6]) * vec.x +
				(matrix[1] * matrix[6] - matrix[0] * matrix[7]) * vec.y +
				(matrix[0] * matrix[4] - matrix[1] * matrix[3]) * vec.z) / det
		);
	}
}

double Matrix3::determinant() const {
	return matrix[0] * (matrix[4] * matrix[8] - matrix[5] * matrix[7]) -
		matrix[1] * (matrix[3] * matrix[8] - matrix[5] * matrix[6]) +
		matrix[2] * (matrix[3] * matrix[7] - matrix[4] * matrix[6]);
}



std::string Matrix3::to_string() {
	return "[" + std::to_string(matrix[0]) + ", " + std::to_string(matrix[1]) + ", " + 
		std::to_string(matrix[2]) + "\n" + std::to_string(matrix[3]) + ", " + 
		std::to_string(matrix[4]) + ", " + std::to_string(matrix[5]) + "\n" + 
		std::to_string(matrix[6]) + ", " + std::to_string(matrix[7]) + ", " + 
		std::to_string(matrix[8]) + "]";
}
