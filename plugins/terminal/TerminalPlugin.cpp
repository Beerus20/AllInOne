#include "TerminalPlugin.hpp"
#include "../../include/utils/Logger.hpp"

namespace AllInOne {
namespace Plugins {

TerminalPlugin::TerminalPlugin()
    : m_name("Terminal"),
      m_version("1.0.0"),
      m_author("AllInOne Team"),
      m_context(nullptr) {
}

TerminalPlugin::~TerminalPlugin() {
}

const std::string& TerminalPlugin::getName() const {
    return m_name;
}

const std::string& TerminalPlugin::getVersion() const {
    return m_version;
}

const std::string& TerminalPlugin::getAuthor() const {
    return m_author;
}

bool TerminalPlugin::onLoad(PluginContext& context) {
    LOG_INFO("Loading Terminal Plugin...");
    m_context = &context;
    
    // TODO: Initialize terminal emulator
    // TODO: Register UI elements
    // TODO: Subscribe to events
    
    return true;
}

void TerminalPlugin::onUnload() {
    LOG_INFO("Unloading Terminal Plugin...");
    
    // TODO: Cleanup terminal emulator
    // TODO: Unregister UI elements
    // TODO: Unsubscribe from events
}

void TerminalPlugin::onUpdate(float deltaTime) {
    // TODO: Update terminal state
    // TODO: Process input/output
}

} // namespace Plugins
} // namespace AllInOne

// Plugin export function
extern "C" {
    AllInOne::Plugins::IPlugin* createPlugin() {
        return new AllInOne::Plugins::TerminalPlugin();
    }
}
