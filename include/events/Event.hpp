#pragma once

#include <string>
#include <any>

namespace AllInOne {
namespace Events {

/**
 * @brief Event types enumeration
 */
enum class EventType {
    None = 0,
    
    // Window events
    WindowClose,
    WindowResize,
    WindowFocus,
    WindowLostFocus,
    
    // Keyboard events
    KeyPressed,
    KeyReleased,
    KeyTyped,
    
    // Mouse events
    MouseButtonPressed,
    MouseButtonReleased,
    MouseMoved,
    MouseScrolled,
    
    // Application events
    AppTick,
    AppUpdate,
    AppRender,
    
    // Custom events
    Custom
};

/**
 * @brief Event class
 * Base event structure for the event system
 */
class Event {
public:
    Event(EventType type) : m_type(type), m_handled(false) {}
    virtual ~Event() = default;

    EventType getType() const { return m_type; }
    bool isHandled() const { return m_handled; }
    void setHandled(bool handled) { m_handled = handled; }

    template<typename T>
    void setData(const std::string& key, const T& value);
    
    template<typename T>
    T getData(const std::string& key, const T& defaultValue = T()) const;

private:
    EventType m_type;
    bool m_handled;
    std::map<std::string, std::any> m_data;
};

// Template implementations
template<typename T>
void Event::setData(const std::string& key, const T& value) {
    m_data[key] = value;
}

template<typename T>
T Event::getData(const std::string& key, const T& defaultValue) const {
    auto it = m_data.find(key);
    if (it != m_data.end()) {
        try {
            return std::any_cast<T>(it->second);
        } catch (const std::bad_any_cast&) {
            return defaultValue;
        }
    }
    return defaultValue;
}

} // namespace Events
} // namespace AllInOne
