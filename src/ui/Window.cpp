#include "../../include/ui/Window.hpp"

namespace AllInOne {
namespace UI {

Window::Window(const std::string& title, float x, float y, float width, float height)
    : m_title(title), m_bounds(x, y, width, height), m_backgroundColor(200, 200, 200, 255) {
}

void Window::render(Core::IRenderer& renderer) {
    // Draw window background
    renderer.drawRect(m_bounds, m_backgroundColor);

    // Draw title bar
    Utils::Rect titleBar(m_bounds.x, m_bounds.y, m_bounds.width, 30);
    renderer.drawRect(titleBar, Utils::Color(100, 100, 100, 255));

    // Draw title text
    renderer.drawText(m_title, Utils::Vec2(m_bounds.x + 10, m_bounds.y + 5), Utils::Color::White);

    // Render children
    for (auto& child : m_children) {
        if (child->isVisible()) {
            child->render(renderer);
        }
    }
}

void Window::handleEvent(const Events::Event& event) {
    // TODO: Handle window dragging, resizing, etc.
    for (auto& child : m_children) {
        if (child->isEnabled()) {
            child->handleEvent(event);
        }
    }
}

void Window::update(float deltaTime) {
    for (auto& child : m_children) {
        if (child->isEnabled()) {
            child->update(deltaTime);
        }
    }
}

void Window::setPosition(float x, float y) {
    m_bounds.x = x;
    m_bounds.y = y;
}

void Window::setSize(float width, float height) {
    m_bounds.width = width;
    m_bounds.height = height;
}

Utils::Rect Window::getBounds() const {
    return m_bounds;
}

void Window::addChild(std::unique_ptr<IWidget> widget) {
    m_children.push_back(std::move(widget));
}

} // namespace UI
} // namespace AllInOne
