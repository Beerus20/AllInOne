#pragma once

# include "../core/IRenderer.hpp"
# include "../utils/Vec2.hpp"
# include "../utils/Color.hpp"
# include "../utils/Rect.hpp"
# include <string>

// Forward declarations for SDL types to avoid including SDL headers
struct SDL_Window;
struct SDL_Renderer;

namespace One {
namespace Backends {

/**
 * @brief SDL2 renderer implementation
 * Simple and portable backend using SDL2 library
 * Ideal for cross-platform development and beginners
 */
class SDLRenderer : public Core::IRenderer
{
	public:
		SDLRenderer();
		~SDLRenderer() override;

		// Core functionality
		bool initialize() override;
		bool initialize(const Core::Data& data) override;
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
		SDL_Window*		m_window;
		SDL_Renderer*	m_renderer;
	    std::string		m_name;
};

} // namespace Backends
} // namespace One
