#pragma once

#include <cstdint>

namespace One {
namespace Utils {

/**
 * @brief Color structure
 * RGBA color representation
 */
struct Color {
    uint8_t r = 255;
    uint8_t g = 255;
    uint8_t b = 255;
    uint8_t a = 255;

    Color() = default;
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
        : r(r), g(g), b(b), a(a) {}

    // Predefined colors
    static const Color White;
    static const Color Black;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color Yellow;
    static const Color Magenta;
    static const Color Cyan;
    static const Color Transparent;

    // Utility functions
    static Color fromHex(uint32_t hex);
    uint32_t toHex() const;
    
    static Color lerp(const Color& a, const Color& b, float t);
};

} // namespace Utils
} // namespace One
