#pragma once

#include "../utils/Rect.hpp"
#include "../events/Event.hpp"

namespace One {
namespace Core {
    class IRenderer;
}
}

namespace One {
namespace UI {

/**
 * @brief Widget interface
 * Base class for all UI widgets
 */
class IWidget {
public:
    virtual ~IWidget() = default;

    virtual void render(Core::IRenderer& renderer) = 0;
    virtual void handleEvent(const Events::Event& event) = 0;
    virtual void update(float deltaTime) = 0;

    virtual void setPosition(float x, float y) = 0;
    virtual void setSize(float width, float height) = 0;
    virtual Utils::Rect getBounds() const = 0;

    virtual bool isVisible() const = 0;
    virtual void setVisible(bool visible) = 0;

    virtual bool isEnabled() const = 0;
    virtual void setEnabled(bool enabled) = 0;
};

} // namespace UI
} // namespace One
