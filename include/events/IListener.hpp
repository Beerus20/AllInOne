#pragma once

#include "Event.hpp"

namespace One {
namespace Events {

/**
 * @brief Event listener interface
 * Classes that want to receive events must implement this
 */
class IListener {
public:
    virtual ~IListener() = default;
    virtual void onEvent(const Event& event) = 0;
};

} // namespace Events
} // namespace One
