#include "../../include/core/Config.hpp"


namespace One {
namespace Core {

Config::Config()
{
    // Default configuration
    m_settings.set("window.width", 1280);
    m_settings.set("window.height", 720);
    m_settings.set("window.title", std::string("One Application"));
    m_settings.set("renderer", std::string("SDL"));
}

bool Config::loadFromFile(const std::string& filepath)
{
    if (!this->m_settings.load(filepath)) {
        return (false);
    }
    return (true);
}

bool Config::saveToFile(const std::string& filepath)
{
    return m_settings.save(filepath, m_settings);
}

const Data& Config::getData(void) const
{
    return (m_settings);
}

} // namespace Core
} // namespace One

std::ostream& operator<<(std::ostream& os, const One::Core::Config& config)
{
    os << config.getData() << std::endl;
    return (os);
}