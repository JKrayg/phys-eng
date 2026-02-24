
#include <string>
#include "matrix3.h"


Vector3 Matrix3::operator*(const Vector3& vec) const {
	return Vector3(
		matrix[0] * vec.x + matrix[1] * vec.y + matrix[2] * vec.z,
		matrix[3] * vec.x + matrix[4] * vec.y + matrix[5] * vec.z,
		matrix[6] * vec.x + matrix[7] * vec.y + matrix[8] * vec.z
	);
}


Matrix3 Matrix3::operator*(const Matrix3& m) const {
	std::array<double, 9> res = {
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

	return Matrix3(res);
}



std::string Matrix3::to_string() {
	return "[" + std::to_string(matrix[0]) + ", " + std::to_string(matrix[1]) + ", " + 
		std::to_string(matrix[2]) + ", " + std::to_string(matrix[3]) + ", " + 
		std::to_string(matrix[4]) + ", " + std::to_string(matrix[5]) + ", " + 
		std::to_string(matrix[6]) + ", " + std::to_string(matrix[7]) + ", " + 
		std::to_string(matrix[8]) + "]";
}
