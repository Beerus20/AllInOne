#pragma once

namespace AllInOne {
namespace Core {
    class IRenderer;
}
namespace Events {
    class EventManager;
}
namespace Resources {
    class ResourceManager;
}
namespace UI {
    class UISystem;
}
}

namespace AllInOne {
namespace Plugins {

/**
 * @brief Plugin context
 * Provides plugins with access to core systems
 */
class PluginContext {
public:
    PluginContext(
        Core::IRenderer* renderer,
        Events::EventManager* eventManager,
        Resources::ResourceManager* resourceManager,
        UI::UISystem* uiSystem
    );

    Core::IRenderer& getRenderer() { return *m_renderer; }
    Events::EventManager& getEventManager() { return *m_eventManager; }
    Resources::ResourceManager& getResourceManager() { return *m_resourceManager; }
    UI::UISystem& getUISystem() { return *m_uiSystem; }

private:
    Core::IRenderer* m_renderer;
    Events::EventManager* m_eventManager;
    Resources::ResourceManager* m_resourceManager;
    UI::UISystem* m_uiSystem;
};

} // namespace Plugins
} // namespace AllInOne
