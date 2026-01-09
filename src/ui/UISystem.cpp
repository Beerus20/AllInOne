#include "../../include/ui/UISystem.hpp"
#include "../../include/utils/Logger.hpp"

namespace AllInOne {
namespace UI {

UISystem::UISystem() {
    LOG_INFO("UI System created");
}

UISystem::~UISystem() {
    clear();
}

void UISystem::addWidget(std::unique_ptr<IWidget> widget) {
    m_widgets.push_back(std::move(widget));
}

void UISystem::removeWidget(IWidget* widget) {
    m_widgets.erase(
        std::remove_if(m_widgets.begin(), m_widgets.end(),
            [widget](const std::unique_ptr<IWidget>& w) { return w.get() == widget; }),
        m_widgets.end()
    );
}

void UISystem::clear() {
    m_widgets.clear();
}

void UISystem::render(Core::IRenderer& renderer) {
    for (auto& widget : m_widgets) {
        if (widget->isVisible()) {
            widget->render(renderer);
        }
    }
}

void UISystem::update(float deltaTime) {
    for (auto& widget : m_widgets) {
        if (widget->isEnabled()) {
            widget->update(deltaTime);
        }
    }
}

void UISystem::handleEvent(const Events::Event& event) {
    for (auto& widget : m_widgets) {
        if (widget->isEnabled()) {
            widget->handleEvent(event);
        }
    }
}

IWidget* UISystem::getWidgetAt(float x, float y) {
    Utils::Vec2 point(x, y);
    for (auto it = m_widgets.rbegin(); it != m_widgets.rend(); ++it) {
        if ((*it)->isVisible() && (*it)->getBounds().contains(point)) {
            return it->get();
        }
    }
    return nullptr;
}

} // namespace UI
} // namespace AllInOne
