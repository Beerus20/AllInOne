#include "../../include/backends/SDLRenderer.hpp"
#include "../../include/utils/Logger.hpp"
#include <SDL2/SDL.h>

// This is a placeholder for SDL renderer implementation
// Uncomment when SDL2 is available:
// #include <SDL2/SDL.h>

namespace One {
namespace Backends {

SDLRenderer::SDLRenderer()
    : m_window(nullptr)
    , m_renderer(nullptr)
    , m_name("SDL") {
}

SDLRenderer::~SDLRenderer() {
    shutdown();
}

bool SDLRenderer::initialize() {
    LOG_INFO("Initializing SDL Renderer...");
    // TODO: Initialize SDL
     if (SDL_Init(SDL_INIT_VIDEO) != 0)
	 {
         LOG_ERROR("SDL initialization failed: " + std::string(SDL_GetError()));
         return (false);
     }
    
    // TODO: Create window
    m_window = SDL_CreateWindow(
        "One Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280, 720,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );
	if (m_window == nullptr)
	{
		LOG_ERROR("SDL window creation failed: " + std::string(SDL_GetError()));
		return (false);
	}
    
    // TODO: Create renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (m_renderer == nullptr)
	{
        LOG_ERROR("SDL renderer creation failed: " + std::string(SDL_GetError()));
        return (false);
    }
    LOG_INFO("SDL Renderer initialized successfully");
    return (true);
}

void SDLRenderer::shutdown() {
    LOG_INFO("Shutting down SDL Renderer...");
    // TODO: Cleanup SDL resources
	if (m_renderer)
	{
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
	}
	if (m_window)
	{
		SDL_DestroyWindow(m_window);
		m_window = nullptr;
	}
	SDL_Quit();
}

void SDLRenderer::beginFrame() {
    // TODO: Begin rendering frame
}

void SDLRenderer::endFrame() {
    // TODO: Present rendered frame
    // SDL_RenderPresent(m_renderer);
}

void SDLRenderer::clear(const Utils::Color& color) {
    (void)color;
    // TODO: Clear screen with color
    // SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    // SDL_RenderClear(m_renderer);
}

void SDLRenderer::drawRect(const Utils::Rect& rect, const Utils::Color& color) {
    (void)rect;
    (void)color;
    // TODO: Draw rectangle
    // SDL_Rect sdlRect = {rect.x, rect.y, rect.width, rect.height};
    // SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    // SDL_RenderFillRect(m_renderer, &sdlRect);
}

void SDLRenderer::drawTexture(int textureId, const Utils::Rect& rect) {
    (void)textureId;
    (void)rect;
    // TODO: Draw texture
}

void SDLRenderer::drawText(const std::string& text, const Utils::Vec2& position, const Utils::Color& color) {
    (void)text;
    (void)position;
    (void)color;
    // TODO: Draw text (requires SDL_ttf)
}

const std::string& SDLRenderer::getName() const {
    return m_name;
}

} // namespace Backends
} // namespace One
