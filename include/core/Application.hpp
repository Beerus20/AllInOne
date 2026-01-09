#pragma once

#include <memory>
#include <string>
#include "IRenderer.hpp"
#include "Config.hpp"
#include "../plugins/PluginManager.hpp"
#include "../events/EventManager.hpp"
#include "../resources/ResourceManager.hpp"
#include "../ui/UISystem.hpp"

namespace AllInOne {
namespace Core {

/**
 * @brief Main application class (Singleton)
 * Manages the entire application lifecycle
 */
class Application {
public:
    static Application& getInstance();

    bool initialize(const Config& config);
    void run();
    void shutdown();

    IRenderer* getRenderer() { return m_renderer.get(); }
    Plugins::PluginManager& getPluginManager() { return *m_pluginManager; }
    Events::EventManager& getEventManager() { return *m_eventManager; }
    Resources::ResourceManager& getResourceManager() { return *m_resourceManager; }
    UI::UISystem& getUISystem() { return *m_uiSystem; }

private:
    Application() = default;
    ~Application() = default;
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    std::unique_ptr<IRenderer> m_renderer;
    std::unique_ptr<Plugins::PluginManager> m_pluginManager;
    std::unique_ptr<Events::EventManager> m_eventManager;
    std::unique_ptr<Resources::ResourceManager> m_resourceManager;
    std::unique_ptr<UI::UISystem> m_uiSystem;

    bool m_running = false;
};

} // namespace Core
} // namespace AllInOne
