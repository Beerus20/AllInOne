#pragma once

# include <ostream>
# include <string>
# include "../data/Data.hpp"

namespace One {
namespace Core {

/**
 * @brief Configuration management
 * Loads and manages application settings
 */
class Config
{
    public:
        Config();
        ~Config() = default;

        bool loadFromFile(const std::string& filepath);
        bool saveToFile(const std::string& filepath);

        template <typename T>
        T               get(const std::string& key) const
        {
            return m_settings.get<T>(key);
        }

        const Data&     getData(void) const;

        template <typename T>
        void            set(const std::string& key, const T& value)
        {
            m_settings.set<T>(key, value);
        }

        
    private:
        Data m_settings;
};

} // namespace Core
} // namespace One

std::ostream& operator<<(std::ostream& os, const One::Core::Config& config);