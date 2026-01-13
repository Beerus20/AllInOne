#pragma once

#include <memory>
#include <vector>
#include <string>
#include "IPlugin.hpp"
#include "PluginContext.hpp"

namespace One {
namespace Plugins {

/**
 * @brief Plugin manager
 * Handles plugin discovery, loading, and lifecycle management
 */
class PluginManager {
public:
    PluginManager();
    ~PluginManager();

    bool loadPlugin(const std::string& filepath);
    bool unloadPlugin(const std::string& name);
    void unloadAll();

    void updatePlugins(float deltaTime);

    IPlugin* getPlugin(const std::string& name);
    std::vector<IPlugin*> getLoadedPlugins();

    void setPluginContext(PluginContext* context);

private:
    std::vector<std::unique_ptr<IPlugin>> m_plugins;
    PluginContext* m_context = nullptr;
};

} // namespace Plugins
} // namespace One
