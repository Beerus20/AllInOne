#pragma once

#include <string>

namespace One {
namespace Resources {

/**
 * @brief Font resource
 * Represents a loaded font
 */
class Font {
public:
    Font(const std::string& filepath, int size);
    ~Font();

    bool load();
    void unload();

    int getId() const { return m_id; }
    int getSize() const { return m_size; }
    const std::string& getFilepath() const { return m_filepath; }

    bool isLoaded() const { return m_loaded; }

private:
    std::string m_filepath;
    int m_id = -1;
    int m_size = 12;
    bool m_loaded = false;
    void* m_data = nullptr;
};

} // namespace Resources
} // namespace One
