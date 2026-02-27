#pragma once

#include <string>
#include <cmath>

class Matrix3;

struct Vector3 {
    double x, y, z;
    
    Vector3(double pos_x = 0, double pos_y = 0, double pos_z = 0)
        : x(pos_x), y(pos_y), z(pos_z) {}

    Vector3 cross(const Vector3& other) const;
    Vector3 inverted() const;
    Vector3 normalize() const;
    Vector3& cross_assign(const Vector3& other);
    Vector3& invert_assign();
    Vector3& normalize_assign();
    Matrix3 skew() const;
    double dot(const Vector3& vec) const;
    double euc_distance(Vector3& vec) const;
    double length() const;
    std::string to_string() const;

    Vector3 operator+(const Vector3& vec) const {
        return Vector3(x + vec.x, y + vec.y, z + vec.z);
    }

    Vector3 operator-(const Vector3& vec) const {
        return Vector3(x - vec.x, y - vec.y, z - vec.z);
    }

    Vector3 operator*(double scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Matrix3 operator*(const Vector3& vec) const;

    Vector3 operator/(double scalar) const {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    Vector3& operator+=(const Vector3& vec) {
        x += vec.x;
        y += vec.y;
        z += vec.z;

        return *this;
    }

    Vector3& operator-=(const Vector3& vec) {
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;

        return *this;
    }

    Vector3& operator*=(const double scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;

        return *this;
    }

    Vector3& operator/=(const double scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;

        return *this;
    }

};