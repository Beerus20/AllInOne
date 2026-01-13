#pragma once

#include <string>

namespace One {
namespace Plugins {

class PluginContext;

/**
 * @brief Plugin interface
 * All plugins must implement this interface
 */
class IPlugin {
public:
    virtual ~IPlugin() = default;

    virtual const std::string& getName() const = 0;
    virtual const std::string& getVersion() const = 0;
    virtual const std::string& getAuthor() const = 0;

    virtual bool onLoad(PluginContext& context) = 0;
    virtual void onUnload() = 0;
    virtual void onUpdate(float deltaTime) = 0;
};

} // namespace Plugins
} // namespace One
