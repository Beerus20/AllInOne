#pragma once

#include "../core/IRenderer.hpp"
#include "../utils/Vec2.hpp"
#include "../utils/Color.hpp"
#include "../utils/Rect.hpp"
#include <string>

namespace One {
namespace Backends {

/**
 * @brief OpenGL renderer implementation
 * High-performance backend using modern OpenGL (3.3+)
 * Supports shaders, advanced rendering techniques, and hardware acceleration
 */
class OpenGLRenderer : public Core::IRenderer {
public:
    OpenGLRenderer();
    ~OpenGLRenderer() override;

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
    void* m_window;  // Platform-specific window handle (GLFW, SDL, etc.)
    unsigned int m_shaderProgram;
    unsigned int m_vao;
    unsigned int m_vbo;
    std::string m_name;

    // Helper methods for OpenGL setup
    bool initializeGLContext();
    bool loadShaders();
    void setupBuffers();
};

} // namespace Backends
} // namespace One
