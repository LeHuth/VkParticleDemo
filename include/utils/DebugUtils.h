//
// Created by Leo on 30.04.25.
//

#ifndef DEBUGUTILS_H
#define DEBUGUTILS_H
#include <vector>
#include <vulkan/vulkan.h>

namespace utils
{
    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };


    class DebugUtils
    {
    public:
        static constexpr bool enableValidationLayers =
#ifdef NDEBUG
false;
#else
            true;
#endif
        DebugUtils();
        ~DebugUtils();
        static VkDebugUtilsMessengerEXT m_debugMessenger;
        static bool checkValidationLayerSupport();
        static std::vector<const char*> getRequiredExtensions();
        static bool isMacOS();
        static void setupDebugMessenger(VkInstance instance);
        static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                            VkDebugUtilsMessageTypeFlagsEXT messageType,
                                                            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                            void* pUserData);
        static void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
        static VkResult CreateDebugUtilsMessengerEXT(VkInstance instance,
                                                     const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator,
                                                     VkDebugUtilsMessengerEXT* pDebugMessenger);

    private:
    };
}
#endif //DEBUGUTILS_H
