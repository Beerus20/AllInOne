#pragma once

#include <string>

namespace One {
namespace Resources {

/**
 * @brief Texture resource
 * Represents a loaded texture
 */
class Texture {
public:
    Texture(const std::string& filepath);
    ~Texture();

    bool load();
    void unload();

    int getId() const { return m_id; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    const std::string& getFilepath() const { return m_filepath; }

    bool isLoaded() const { return m_loaded; }

private:
    std::string m_filepath;
    int m_id = -1;
    int m_width = 0;
    int m_height = 0;
    bool m_loaded = false;
    void* m_data = nullptr;
};

} // namespace Resources
} // namespace One
