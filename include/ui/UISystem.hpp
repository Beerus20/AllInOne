#pragma once

#include <vector>
#include <memory>
#include "IWidget.hpp"

namespace AllInOne {
namespace UI {

/**
 * @brief UI system manager
 * Manages all UI widgets and layout
 */
class UISystem {
public:
    UISystem();
    ~UISystem();

    void addWidget(std::unique_ptr<IWidget> widget);
    void removeWidget(IWidget* widget);
    void clear();

    void render(Core::IRenderer& renderer);
    void update(float deltaTime);
    void handleEvent(const Events::Event& event);

    IWidget* getWidgetAt(float x, float y);

private:
    std::vector<std::unique_ptr<IWidget>> m_widgets;
};

} // namespace UI
} // namespace AllInOne
