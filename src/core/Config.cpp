#include "../../include/core/Config.hpp"
#include <fstream>
#include <sstream>

namespace AllInOne {
namespace Core {

Config::Config() {
    // Default configuration
    m_settings["window.width"] = "1280";
    m_settings["window.height"] = "720";
    m_settings["window.title"] = "AllInOne Application";
    m_settings["renderer"] = "SDL";
}

bool Config::loadFromFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Skip comments and empty lines
        if (line.empty() || line[0] == '#') continue;

        size_t pos = line.find('=');
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            m_settings[key] = value;
        }
    }

    file.close();
    return true;
}

bool Config::saveToFile(const std::string& filepath) {
    std::ofstream file(filepath);
    if (!file.is_open()) {
        return false;
    }

    for (const auto& [key, value] : m_settings) {
        file << key << "=" << value << "\n";
    }

    file.close();
    return true;
}

std::string Config::getString(const std::string& key, const std::string& defaultValue) const {
    auto it = m_settings.find(key);
    return (it != m_settings.end()) ? it->second : defaultValue;
}

int Config::getInt(const std::string& key, int defaultValue) const {
    auto it = m_settings.find(key);
    if (it != m_settings.end()) {
        return std::stoi(it->second);
    }
    return defaultValue;
}

float Config::getFloat(const std::string& key, float defaultValue) const {
    auto it = m_settings.find(key);
    if (it != m_settings.end()) {
        return std::stof(it->second);
    }
    return defaultValue;
}

bool Config::getBool(const std::string& key, bool defaultValue) const {
    auto it = m_settings.find(key);
    if (it != m_settings.end()) {
        return it->second == "true" || it->second == "1";
    }
    return defaultValue;
}

void Config::set(const std::string& key, const std::string& value) {
    m_settings[key] = value;
}

} // namespace Core
} // namespace AllInOne
