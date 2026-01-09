# Plugin Development Guide

## Creating a Plugin

### 1. Implement IPlugin Interface
```cpp
class MyPlugin : public IPlugin {
public:
    bool onLoad(PluginContext& context) override;
    void onUnload() override;
    void onUpdate(float deltaTime) override;
};
```

### 2. Register Your Plugin
Plugins are automatically discovered in the `plugins/` directory.

### 3. Build Configuration
Each plugin should have its own CMakeLists.txt file.

## Plugin Context
The PluginContext provides access to:
- Resource manager
- Event system
- UI system
- Application configuration

## Example Plugins
- Video Player
- Image Viewer
- Terminal Emulator
