#pragma once

#include "IWidget.hpp"
#include "../utils/Color.hpp"
#include <string>

namespace AllInOne {
namespace UI {

/**
 * @brief Window widget
 * Represents a window with title bar and content area
 */
class Window : public IWidget {
public:
    Window(const std::string& title, float x, float y, float width, float height);
    ~Window() override = default;

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

    void setTitle(const std::string& title) { m_title = title; }
    const std::string& getTitle() const { return m_title; }

    void addChild(std::unique_ptr<IWidget> widget);

private:
    std::string m_title;
    Utils::Rect m_bounds;
    Utils::Color m_backgroundColor;
    bool m_visible = true;
    bool m_enabled = true;
    bool m_dragging = false;
    
    std::vector<std::unique_ptr<IWidget>> m_children;
};

} // namespace UI
} // namespace AllInOne
