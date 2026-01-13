#include "../../include/plugins/PluginManager.hpp"
#include "../../include/utils/Logger.hpp"

namespace One {
namespace Plugins {

PluginManager::PluginManager() {
    LOG_INFO("Plugin Manager created");
}

PluginManager::~PluginManager() {
    unloadAll();
}

bool PluginManager::loadPlugin(const std::string& filepath) {
    (void)filepath;
    LOG_INFO("Loading plugin: " + filepath);
    // TODO: Implement dynamic library loading
    return false;
}

bool PluginManager::unloadPlugin(const std::string& name) {
    (void)name;
    LOG_INFO("Unloading plugin: " + name);
    // TODO: Find and unload plugin
    return false;
}

void PluginManager::unloadAll() {
    LOG_INFO("Unloading all plugins...");
    for (auto& plugin : m_plugins) {
        plugin->onUnload();
    }
    m_plugins.clear();
}

void PluginManager::updatePlugins(float deltaTime) {
    for (auto& plugin : m_plugins) {
        plugin->onUpdate(deltaTime);
    }
}

IPlugin* PluginManager::getPlugin(const std::string& name) {
    for (auto& plugin : m_plugins) {
        if (plugin->getName() == name) {
            return plugin.get();
        }
    }
    return nullptr;
}

std::vector<IPlugin*> PluginManager::getLoadedPlugins() {
    std::vector<IPlugin*> plugins;
    for (auto& plugin : m_plugins) {
        plugins.push_back(plugin.get());
    }
    return plugins;
}

void PluginManager::setPluginContext(PluginContext* context) {
    (void)context;
    m_context = context;
}

} // namespace Plugins
} // namespace One
