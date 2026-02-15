#pragma once

#include "constants.h"
#include "vector3.h"

struct Math {

	Vector3 force(const double& mass, const Vector3& acceleration) const {
		return acceleration * mass;
	}

	double rest_energy(const double& mass) const {
		return mass * (Constants::SPEED_O_LIGHT * Constants::SPEED_O_LIGHT);
	}

	Vector3 centripetal_acceleration(
		const Vector3& velocity,
		const Vector3& obj_pos,
		const Vector3& center_pos
	) const;

	double magnitude(const Vector3& vec) const {
		return std::sqrt(
			vec.x * vec.x +
			vec.y * vec.y +
			vec.z * vec.z
		);
	}

};
