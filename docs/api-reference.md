# API Reference

## Core API

### Application
```cpp
class Application {
public:
    static Application& getInstance();
    bool initialize(const Config& config);
    void run();
    void shutdown();
};
```

### IRenderer
```cpp
class IRenderer {
public:
    virtual bool initialize() = 0;
    virtual void beginFrame() = 0;
    virtual void endFrame() = 0;
    virtual void drawRect(const Rect& rect, const Color& color) = 0;
};
```

## Plugin API

### IPlugin
```cpp
class IPlugin {
public:
    virtual bool onLoad(PluginContext& context) = 0;
    virtual void onUnload() = 0;
    virtual void onUpdate(float deltaTime) = 0;
};
```

## UI API

### IWidget
```cpp
class IWidget {
public:
    virtual void render(IRenderer& renderer) = 0;
    virtual void handleEvent(const Event& event) = 0;
};
```

## Event API

### EventManager
```cpp
class EventManager {
public:
    void subscribe(EventType type, IListener* listener);
    void unsubscribe(EventType type, IListener* listener);
    void emit(const Event& event);
};
```
