//
// Created by leona on 31.03.2025.
//

#ifndef APP_H
#define APP_H
#include <vector>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan_core.h>

namespace sph
{
    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

    class VkApp
    {
    public:
        static constexpr bool enableValidationLayers =
#ifdef NDEBUG
    false;
#else
            true;
#endif
        VkApp() :
            _window(nullptr),
            _instance(nullptr),
            _debugMessenger(nullptr),
            _physicalDevice(VK_NULL_HANDLE),
            _device(nullptr),
            _graphicsQueue(nullptr),
            _pipelineLayout(VK_NULL_HANDLE),
            _renderPass(VK_NULL_HANDLE),
            _graphicsPipeline(VK_NULL_HANDLE),
            _commandPool(VK_NULL_HANDLE),
            _commandBuffer(VK_NULL_HANDLE),
            _imageAvailableSemaphore(VK_NULL_HANDLE),
            _renderFinishedSemaphore(VK_NULL_HANDLE),
            _inFlightFence(VK_NULL_HANDLE),
            _surface(nullptr),
            _presentQueue(nullptr),
            _swapChain(nullptr),
            _swapChainImageFormat(VK_FORMAT_R8G8B8A8_SRGB),
            _swapChainExtent({})
        {
        }

        void run();

    private:
        GLFWwindow* _window;
        VkInstance _instance;
        VkDebugUtilsMessengerEXT _debugMessenger;
        VkPhysicalDevice _physicalDevice;
        VkDevice _device;
        VkQueue _graphicsQueue;
        VkPipelineLayout _pipelineLayout;
        VkRenderPass _renderPass;
        VkPipeline _graphicsPipeline;
        std::vector<VkFramebuffer> _swapChainFramebuffers{};
        VkCommandPool _commandPool;
        VkCommandBuffer _commandBuffer;
        VkSemaphore _imageAvailableSemaphore;
        VkSemaphore _renderFinishedSemaphore;
        VkFence _inFlightFence;
        VkSurfaceKHR _surface;
        VkQueue _presentQueue;
        VkSwapchainKHR _swapChain;
        std::vector<VkImage> _swapChainImages{};
        std::vector<VkImageView> _swapChainImageViews{};
        VkFormat _swapChainImageFormat;
        VkExtent2D _swapChainExtent;

        void initWindow();
        void initVulkan();
        void mainLoop();
        void cleanup();

        void createInstance();
        void setupDebugMessenger();
        void createSurface();
        void pickPhysicalDevice();
        void createLogicalDevice();
        void createSwapChain();
        void createImageViews();
        void createRenderPass();
        void createGraphicsPipeline();
        void createFramebuffers();
        void createCommandPool();
        void createCommandBuffer();
        void createSyncObjects();

        void drawFrame();
        bool checkValidationLayerSupport();
        std::vector<const char*> getRequiredExtensions();
    };
}
#endif //APP_H
