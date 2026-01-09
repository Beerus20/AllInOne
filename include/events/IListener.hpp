#pragma once

#include "Event.hpp"

namespace AllInOne {
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
} // namespace AllInOne
