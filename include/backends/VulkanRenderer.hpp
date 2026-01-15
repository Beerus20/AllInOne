#pragma once

#include "../core/IRenderer.hpp"
#include "../utils/Vec2.hpp"
#include "../utils/Color.hpp"
#include "../utils/Rect.hpp"
#include <string>
#include <vector>

// Forward declarations for Vulkan types
struct VkInstance_T;
struct VkPhysicalDevice_T;
struct VkDevice_T;
struct VkQueue_T;
struct VkSwapchainKHR_T;
struct VkCommandPool_T;
struct VkCommandBuffer_T;

typedef VkInstance_T* VkInstance;
typedef VkPhysicalDevice_T* VkPhysicalDevice;
typedef VkDevice_T* VkDevice;
typedef VkQueue_T* VkQueue;
typedef VkSwapchainKHR_T* VkSwapchainKHR;
typedef VkCommandPool_T* VkCommandPool;
typedef VkCommandBuffer_T* VkCommandBuffer;

namespace One {
namespace Backends {

/**
 * @brief Vulkan renderer implementation
 * Modern, low-level graphics API for maximum performance and control
 * Provides explicit control over GPU resources and synchronization
 * Best for advanced users and high-performance applications
 */
class VulkanRenderer : public Core::IRenderer {
public:
    VulkanRenderer();
    ~VulkanRenderer() override;

    // Core functionality
    bool initialize() override;
	bool initialize(const Core::Data&) override {return (false);};
    void shutdown() override;

    // Frame management
    void beginFrame() override;
    void endFrame() override;
    void clear(const Utils::Color& color) override;

    // Drawing operations
    void drawRect(const Utils::Rect& rect, const Utils::Color& color) override;
    void drawTexture(int textureId, const Utils::Rect& rect) override;
    void drawText(const std::string& text, const Utils::Vec2& position, const Utils::Color& color) override;

    // Renderer information
    const std::string& getName() const override;

private:
    // Vulkan core objects
    VkInstance m_instance;
    VkPhysicalDevice m_physicalDevice;
    VkDevice m_device;
    VkQueue m_graphicsQueue;
    VkQueue m_presentQueue;
    VkSwapchainKHR m_swapchain;
    VkCommandPool m_commandPool;
    std::vector<VkCommandBuffer> m_commandBuffers;

    // Window and surface
    void* m_window;  // Platform-specific window handle
    void* m_surface; // VkSurfaceKHR

    // Helper data
    std::string m_name;
    uint32_t m_currentFrame;
    uint32_t m_imageIndex;

    // Initialization helpers
    bool createInstance();
    bool selectPhysicalDevice();
    bool createLogicalDevice();
    bool createSwapchain();
    bool createCommandPool();
    bool createCommandBuffers();
    
    // Cleanup helpers
    void cleanupSwapchain();
};

} // namespace Backends
} // namespace One
