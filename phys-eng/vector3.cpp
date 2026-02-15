
#include "vector3.h"

Vector3 Vector3::cross(const Vector3& other) const {
    return Vector3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

Vector3 Vector3::inverted() const {
    return Vector3(-x, -y, -z);
}

Vector3 Vector3::normalize() const {
    double len = length();
    return Vector3(x/len, y/len, z/len);
}

Vector3& Vector3::cross_assign(const Vector3& other) {
    double new_x = y * other.z - z * other.y;
    double new_y = z * other.x - x * other.z;
    double new_z = x * other.y - y * other.x;

    x = new_x;
    y = new_y;
    z = new_z;

    return *this;
}

Vector3& Vector3::invert_assign() {
    x = -x;
    y = -y;
    z = -z;

    return *this;
}

Vector3& Vector3::normalize_assign() {
    double len = this->length();
    x = x / len;
    y = y / len;
    z = z / len;

    return *this;
}

double Vector3::dot(const Vector3& vec) const {
    return x * vec.x + y * vec.y + z * vec.z;
}

double Vector3::euc_distance(Vector3& vec) const {
    Vector3 diff = *this - vec;

    return diff.length();
}

double Vector3::length() const {
    return std::sqrt(x*x + y*y + z*z);
}

std::string Vector3::to_string() const {
    return "[" + std::to_string(x) +
        ", " + std::to_string(y) +
        ", " + std::to_string(z) + "]";
}
