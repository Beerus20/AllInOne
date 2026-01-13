#pragma once

namespace One {
namespace Utils {

/**
 * @brief 2D Vector
 * Simple 2D vector for positions and directions
 */
struct Vec2 {
    float x = 0.0f;
    float y = 0.0f;

    Vec2() = default;
    Vec2(float x, float y) : x(x), y(y) {}

    Vec2 operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 operator-(const Vec2& other) const {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2 operator*(float scalar) const {
        return Vec2(x * scalar, y * scalar);
    }

    Vec2 operator/(float scalar) const {
        return Vec2(x / scalar, y / scalar);
    }

    float length() const;
    float lengthSquared() const;
    Vec2 normalized() const;
    float dot(const Vec2& other) const;
};

} // namespace Utils
} // namespace One
