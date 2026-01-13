#include "../../include/resources/Font.hpp"

namespace One {
namespace Resources {

Font::Font(const std::string& filepath, int size)
    : m_filepath(filepath), m_id(-1), m_size(size), m_loaded(false), m_data(nullptr) {
}

Font::~Font() {
    unload();
}

bool Font::load() {
    if (m_loaded) {
        return true;
    }
    
    // TODO: Implement actual font loading
    // For now, just mark as loaded
    m_loaded = true;
    m_id = 0; // Placeholder ID
    
    return true;
}

void Font::unload() {
    if (m_loaded) {
        // TODO: Implement actual font unloading
        m_loaded = false;
        m_id = -1;
        m_data = nullptr;
    }
}

} // namespace Resources
} // namespace One
