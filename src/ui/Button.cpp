#include "../../include/ui/Button.hpp"

namespace One {
namespace UI {

Button::Button(const std::string& label, float x, float y, float width, float height)
    : m_label(label), 
      m_bounds(x, y, width, height),
      m_normalColor(180, 180, 180, 255),
      m_hoverColor(200, 200, 200, 255),
      m_pressedColor(150, 150, 150, 255) {
}

void Button::render(Core::IRenderer& renderer) {
    (void)renderer;
    Utils::Color currentColor = m_normalColor;
    if (!m_enabled) {
        currentColor = Utils::Color(100, 100, 100, 255);
    } else if (m_pressed) {
        currentColor = m_pressedColor;
    } else if (m_hovered) {
        currentColor = m_hoverColor;
    }

    //renderer.drawRect(m_bounds, currentColor);
    
    // Draw label centered
    Utils::Vec2 textPos = m_bounds.center();

    (void)textPos;
    //renderer.drawText(m_label, textPos, Utils::Color::Black);
}

void Button::handleEvent(const Events::Event& event) {
    (void)event;
    if (!m_enabled) return;

    // TODO: Handle mouse events for hover, press, and click
    // This requires proper event type checking
}

void Button::update(float deltaTime) {
    (void)deltaTime;
    // Button updates if needed
}

void Button::setPosition(float x, float y) {
    m_bounds.x = x;
    m_bounds.y = y;
}

void Button::setSize(float width, float height) {
    m_bounds.width = width;
    m_bounds.height = height;
}

Utils::Rect Button::getBounds() const {
    return m_bounds;
}

} // namespace UI
} // namespace One
