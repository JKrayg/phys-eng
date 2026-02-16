// classical equations

#include "vector3.h"
#include "physics.h"

Vector3 Physics::centripetal_acceleration(
	const Vector3& velocity,
	const Vector3& obj_pos,
	const Vector3& center_pos) const {

	Vector3 r_diff = center_pos - obj_pos;
	double r = magnitude(r_diff);
	double v_sqr = (
		velocity.x * velocity.x +
		velocity.y * velocity.y +
		velocity.z * velocity.z
	);
	Vector3 r_hat = r_diff / r;

	Vector3 a = r_hat * (v_sqr / r);
	return a;
}
