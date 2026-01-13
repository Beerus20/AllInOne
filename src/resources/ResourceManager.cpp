#include "../../include/resources/ResourceManager.hpp"
#include "../../include/utils/Logger.hpp"

namespace One {
namespace Resources {

ResourceManager::ResourceManager() {
    LOG_INFO("Resource Manager created");
}

ResourceManager::~ResourceManager() {
    unloadAll();
}

Texture* ResourceManager::loadTexture(const std::string& filepath) {
    // Check if already loaded
    auto it = m_textures.find(filepath);
    if (it != m_textures.end()) {
        return it->second.get();
    }

    // Load new texture
    auto texture = std::make_unique<Texture>(filepath);
    if (texture->load()) {
        auto* ptr = texture.get();
        m_textures[filepath] = std::move(texture);
        return ptr;
    }

    return nullptr;
}

Texture* ResourceManager::getTexture(const std::string& name) {
    auto it = m_textures.find(name);
    return (it != m_textures.end()) ? it->second.get() : nullptr;
}

void ResourceManager::unloadTexture(const std::string& name) {
    m_textures.erase(name);
}

Font* ResourceManager::loadFont(const std::string& filepath, int size) {
    std::string key = filepath + "_" + std::to_string(size);
    
    auto it = m_fonts.find(key);
    if (it != m_fonts.end()) {
        return it->second.get();
    }

    auto font = std::make_unique<Font>(filepath, size);
    if (font->load()) {
        auto* ptr = font.get();
        m_fonts[key] = std::move(font);
        return ptr;
    }

    return nullptr;
}

Font* ResourceManager::getFont(const std::string& name) {
    auto it = m_fonts.find(name);
    return (it != m_fonts.end()) ? it->second.get() : nullptr;
}

void ResourceManager::unloadFont(const std::string& name) {
    m_fonts.erase(name);
}

void ResourceManager::unloadAll() {
    LOG_INFO("Unloading all resources...");
    m_textures.clear();
    m_fonts.clear();
}

void ResourceManager::unloadUnused() {
    // TODO: Implement reference counting to unload unused resources
}

} // namespace Resources
} // namespace One
