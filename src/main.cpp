#include "../include/core/Application.hpp"
#include "../include/core/Config.hpp"
#include "../include/utils/Logger.hpp"

int main(int argc, char* argv[]) {
    using namespace AllInOne;

    // Initialize logger
    Utils::Logger::getInstance().setLogLevel(Utils::LogLevel::Info);
    LOG_INFO("Starting AllInOne Application...");

    // Load configuration
    Core::Config config;
    config.loadFromFile("assets/config/default-config.json");

    // Initialize application
    auto& app = Core::Application::getInstance();
    if (!app.initialize(config)) {
        LOG_ERROR("Failed to initialize application");
        return 1;
    }

    // Run application
    app.run();

    // Shutdown
    app.shutdown();

    LOG_INFO("Application terminated");
    return 0;
}
