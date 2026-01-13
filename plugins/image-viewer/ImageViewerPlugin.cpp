#include "ImageViewerPlugin.hpp"
#include "../../include/utils/Logger.hpp"

namespace One {
namespace Plugins {

ImageViewerPlugin::ImageViewerPlugin()
    : m_name("Image Viewer"),
      m_version("1.0.0"),
      m_author("One Team"),
      m_context(nullptr) {
}

ImageViewerPlugin::~ImageViewerPlugin() {
}

const std::string& ImageViewerPlugin::getName() const {
    return m_name;
}

const std::string& ImageViewerPlugin::getVersion() const {
    return m_version;
}

const std::string& ImageViewerPlugin::getAuthor() const {
    return m_author;
}

bool ImageViewerPlugin::onLoad(PluginContext& context) {
    (void)context;
    LOG_INFO("Loading Image Viewer Plugin...");
    m_context = &context;
    
    // TODO: Initialize image viewer components
    // TODO: Register UI elements
    // TODO: Subscribe to events
    
    return true;
}

void ImageViewerPlugin::onUnload() {
    LOG_INFO("Unloading Image Viewer Plugin...");
    
    // TODO: Cleanup image viewer components
    // TODO: Unregister UI elements
    // TODO: Unsubscribe from events
}

void ImageViewerPlugin::onUpdate(float deltaTime) {
    (void)deltaTime;
    // TODO: Update image viewer state
}

} // namespace Plugins
} // namespace One

// Plugin export function
extern "C" {
    One::Plugins::IPlugin* createPlugin() {
        return new One::Plugins::ImageViewerPlugin();
    }
}
