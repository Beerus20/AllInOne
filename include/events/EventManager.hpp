#pragma once

#include <vector>
#include <map>
#include <functional>
#include "Event.hpp"
#include "IListener.hpp"

namespace One {
namespace Events {

/**
 * @brief Event manager
 * Central event dispatcher using observer pattern
 */
class EventManager {
public:
    EventManager();
    ~EventManager();

    void subscribe(EventType type, IListener* listener);
    void unsubscribe(EventType type, IListener* listener);
    void unsubscribeAll(IListener* listener);

    void emit(const Event& event);
    void queueEvent(const Event& event);
    void processQueue();

private:
    std::map<EventType, std::vector<IListener*>>	m_listeners;
    std::vector<Event>								m_eventQueue;
};

} // namespace Events
} // namespace One
