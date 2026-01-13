#include "../include/core/Application.hpp"
#include "../include/core/Config.hpp"
#include "../include/utils/Logger.hpp"
#include "../include/data/json.hpp"

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;
    using namespace One;

    // Initialize logger
    Utils::Logger::getInstance().setLogLevel(Utils::LogLevel::Info);
    LOG_INFO("Starting One Application...");

    // Load configuration
    Core::Config config;
    config.loadFromFile("assets/config/default-config.json");

    std::cout << config << std::endl;
    JSON window = config.get<JSON>("window");
    std::cout << "WINDOW : " << window << std::endl;
    // Initialize application
    auto& app = Core::Application::getInstance();
    if (!app.initialize(config)) {
        LOG_ERROR("Failed to initialize application");
        return 1;
    }

    // Run application
    //app.run();

    //// Shutdown
    //app.shutdown();

    LOG_INFO("Application terminated");
    return 0;
}
