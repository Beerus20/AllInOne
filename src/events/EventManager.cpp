#include "../../include/events/EventManager.hpp"
#include "../../include/utils/Logger.hpp"

namespace AllInOne {
namespace Events {

EventManager::EventManager() {
    LOG_INFO("Event Manager created");
}

EventManager::~EventManager() {
    m_listeners.clear();
}

void EventManager::subscribe(EventType type, IListener* listener) {
    m_listeners[type].push_back(listener);
}

void EventManager::unsubscribe(EventType type, IListener* listener) {
    auto& listeners = m_listeners[type];
    listeners.erase(
        std::remove(listeners.begin(), listeners.end(), listener),
        listeners.end()
    );
}

void EventManager::unsubscribeAll(IListener* listener) {
    for (auto& [type, listeners] : m_listeners) {
        listeners.erase(
            std::remove(listeners.begin(), listeners.end(), listener),
            listeners.end()
        );
    }
}

void EventManager::emit(const Event& event) {
    auto it = m_listeners.find(event.getType());
    if (it != m_listeners.end()) {
        for (auto* listener : it->second) {
            listener->onEvent(event);
            if (event.isHandled()) {
                break;
            }
        }
    }
}

void EventManager::queueEvent(const Event& event) {
    m_eventQueue.push_back(event);
}

void EventManager::processQueue() {
    for (const auto& event : m_eventQueue) {
        emit(event);
    }
    m_eventQueue.clear();
}

} // namespace Events
} // namespace AllInOne
