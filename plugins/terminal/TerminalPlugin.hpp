#pragma once

#include "../../include/plugins/IPlugin.hpp"
#include "../../include/plugins/PluginContext.hpp"

namespace One {
namespace Plugins {

/**
 * @brief Terminal Plugin
 * Provides terminal emulator functionality
 */
class TerminalPlugin : public IPlugin {
public:
    TerminalPlugin();
    ~TerminalPlugin() override;

    const std::string& getName() const override;
    const std::string& getVersion() const override;
    const std::string& getAuthor() const override;

    bool onLoad(PluginContext& context) override;
    void onUnload() override;
    void onUpdate(float deltaTime) override;

private:
    std::string m_name;
    std::string m_version;
    std::string m_author;
    PluginContext* m_context;
};

} // namespace Plugins
} // namespace One
