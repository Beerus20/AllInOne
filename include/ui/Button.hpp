#pragma once

#include "IWidget.hpp"
#include "../utils/Color.hpp"
#include <string>
#include <functional>

namespace One {
namespace UI {

/**
 * @brief Button widget
 * Clickable button with label
 */
class Button : public IWidget {
public:
    using ClickCallback = std::function<void()>;

    Button(const std::string& label, float x, float y, float width, float height);
    ~Button() override = default;

    void render(Core::IRenderer& renderer) override;
    void handleEvent(const Events::Event& event) override;
    void update(float deltaTime) override;

    void setPosition(float x, float y) override;
    void setSize(float width, float height) override;
    Utils::Rect getBounds() const override;

    bool isVisible() const override { return m_visible; }
    void setVisible(bool visible) override { m_visible = visible; }

    bool isEnabled() const override { return m_enabled; }
    void setEnabled(bool enabled) override { m_enabled = enabled; }

    void setLabel(const std::string& label) { m_label = label; }
    const std::string& getLabel() const { return m_label; }

    void setOnClick(ClickCallback callback) { m_onClick = callback; }

private:
    std::string m_label;
    Utils::Rect m_bounds;
    Utils::Color m_normalColor;
    Utils::Color m_hoverColor;
    Utils::Color m_pressedColor;
    bool m_visible = true;
    bool m_enabled = true;
    bool m_hovered = false;
    bool m_pressed = false;

    ClickCallback m_onClick;
};

} // namespace UI
} // namespace One
