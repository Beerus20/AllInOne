#include "../../include/core/Application.hpp"
#include "../../include/utils/Logger.hpp"

namespace AllInOne {
namespace Core {

Application& Application::getInstance() {
    static Application instance;
    return instance;
}

bool Application::initialize(const Config& config) {
    LOG_INFO("Initializing application...");

    // TODO: Initialize renderer based on config
    // TODO: Initialize plugin manager
    // TODO: Initialize event manager
    // TODO: Initialize resource manager
    // TODO: Initialize UI system

    LOG_INFO("Application initialized successfully");
    return true;
}

void Application::run() {
    LOG_INFO("Running application...");
    m_running = true;

    while (m_running) {
        // TODO: Handle events
        // TODO: Update plugins
        // TODO: Update UI
        // TODO: Render
    }
}

void Application::shutdown() {
    LOG_INFO("Shutting down application...");
    m_running = false;

    // TODO: Cleanup all systems
    
    LOG_INFO("Application shutdown complete");
}

} // namespace Core
} // namespace AllInOne
