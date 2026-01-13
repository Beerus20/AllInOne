#pragma once

#include <string>
#include <map>
#include <memory>
#include "Texture.hpp"
#include "Font.hpp"

namespace One {
namespace Resources {

/**
 * @brief Resource manager
 * Manages loading, caching, and unloading of resources
 */
class ResourceManager {
public:
    ResourceManager();
    ~ResourceManager();

    // Texture management
    Texture* loadTexture(const std::string& filepath);
    Texture* getTexture(const std::string& name);
    void unloadTexture(const std::string& name);

    // Font management
    Font* loadFont(const std::string& filepath, int size);
    Font* getFont(const std::string& name);
    void unloadFont(const std::string& name);

    // Resource cleanup
    void unloadAll();
    void unloadUnused();

private:
    std::map<std::string, std::unique_ptr<Texture>> m_textures;
    std::map<std::string, std::unique_ptr<Font>> m_fonts;
};

} // namespace Resources
} // namespace One
