#include "../../include/resources/Texture.hpp"
#include "../../include/utils/Logger.hpp"

namespace One {
namespace Resources {

Texture::Texture(const std::string& filepath)
    : m_filepath(filepath) {
}

Texture::~Texture() {
    unload();
}

bool Texture::load() {
    LOG_INFO("Loading texture: " + m_filepath);
    // TODO: Implement actual texture loading (stb_image, SDL_image, etc.)
    m_loaded = true;
    return true;
}

void Texture::unload() {
    if (m_loaded) {
        LOG_INFO("Unloading texture: " + m_filepath);
        // TODO: Free texture data
        m_loaded = false;
        m_data = nullptr;
    }
}

} // namespace Resources
} // namespace One
