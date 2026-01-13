#pragma once

# include "../utils/Vec2.hpp"
# include "../utils/Color.hpp"
# include "../utils/Rect.hpp"
# include <string>

namespace One {
namespace Core {

/**
 * @brief Abstract renderer interface
 * Allows multiple rendering backends (SDL, OpenGL, MinilibX, Vulkan)
 */
class IRenderer {
public:
    virtual ~IRenderer() = default;

    virtual bool initialize() = 0;
    virtual void shutdown() = 0;

    virtual void beginFrame() = 0;
    virtual void endFrame() = 0;
    virtual void clear(const Utils::Color& color) = 0;

    virtual void drawRect(const Utils::Rect& rect, const Utils::Color& color) = 0;
    virtual void drawTexture(int textureId, const Utils::Rect& rect) = 0;
    virtual void drawText(const std::string& text, const Utils::Vec2& position, const Utils::Color& color) = 0;

    virtual const std::string& getName() const = 0;
};

} // namespace Core
} // namespace One
