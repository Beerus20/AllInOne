#pragma once

#include <string>
#include <map>

namespace AllInOne {
namespace Core {

/**
 * @brief Configuration management
 * Loads and manages application settings
 */
class Config {
public:
    Config();
    ~Config() = default;

    bool loadFromFile(const std::string& filepath);
    bool saveToFile(const std::string& filepath);

    std::string getString(const std::string& key, const std::string& defaultValue = "") const;
    int getInt(const std::string& key, int defaultValue = 0) const;
    float getFloat(const std::string& key, float defaultValue = 0.0f) const;
    bool getBool(const std::string& key, bool defaultValue = false) const;

    void set(const std::string& key, const std::string& value);

private:
    std::map<std::string, std::string> m_settings;
};

} // namespace Core
} // namespace AllInOne
