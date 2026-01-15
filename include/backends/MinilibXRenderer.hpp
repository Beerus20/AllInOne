#pragma once

#include "../core/IRenderer.hpp"
#include "../utils/Vec2.hpp"
#include "../utils/Color.hpp"
#include "../utils/Rect.hpp"
#include <string>

// Forward declarations for MinilibX types
typedef void* t_xvar;
typedef void* t_win_list;

namespace One {
namespace Backends {

/**
 * @brief MinilibX renderer implementation
 * Specialized backend for École 42 projects
 * Compatible with 42's graphics library requirements
 * Suitable for so_long, cub3d, fdf, and similar projects
 */
class MinilibXRenderer : public Core::IRenderer {
public:
    MinilibXRenderer();
    ~MinilibXRenderer() override;

    // Core functionality
    bool initialize() override;
    void shutdown() override;

    // Frame management
    void beginFrame() override;
    void endFrame() override;
    void clear(const Utils::Color& color) override;

    // Drawing operations
    void drawRect(const Utils::Rect& rect, const Utils::Color& color) override;
    void drawTexture(int textureId, const Utils::Rect& rect) override;
    void drawText(const std::string& text, const Utils::Vec2& position, const Utils::Color& color) override;

    // Renderer information
    const std::string& getName() const override;

private:
    t_xvar m_mlx;
    t_win_list m_window;
    void* m_image;
    char* m_imageData;
    int m_bitsPerPixel;
    int m_lineLength;
    int m_endian;
    int m_width;
    int m_height;
    std::string m_name;

    // Helper methods for MinilibX
    void putPixel(int x, int y, const Utils::Color& color);
    unsigned int colorToInt(const Utils::Color& color);
};

} // namespace Backends
} // namespace One
