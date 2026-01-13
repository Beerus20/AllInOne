#pragma once

#include "Vec2.hpp"

namespace One {
namespace Utils {

/**
 * @brief Rectangle structure
 * Represents a 2D rectangle
 */
struct Rect {
    float x = 0.0f;
    float y = 0.0f;
    float width = 0.0f;
    float height = 0.0f;

    Rect() = default;
    Rect(float x, float y, float width, float height)
        : x(x), y(y), width(width), height(height) {}

    float left() const { return x; }
    float right() const { return x + width; }
    float top() const { return y; }
    float bottom() const { return y + height; }

    Vec2 center() const {
        return Vec2(x + width / 2.0f, y + height / 2.0f);
    }

    bool contains(const Vec2& point) const {
        return point.x >= x && point.x <= x + width &&
               point.y >= y && point.y <= y + height;
    }

    bool intersects(const Rect& other) const {
        return !(right() < other.left() || left() > other.right() ||
                 bottom() < other.top() || top() > other.bottom());
    }
};

} // namespace Utils
} // namespace One
