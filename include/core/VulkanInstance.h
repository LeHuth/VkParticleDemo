//
// Created by Leo on 30.04.25.
//
#include <vulkan/vulkan.h>
#ifndef VULKANINSTANCE_H
#define VULKANINSTANCE_H

namespace core
{
    class VulkanInstance
    {
    public:
        VulkanInstance();
        ~VulkanInstance();

    private:
        VkInstance m_instance = VK_NULL_HANDLE;

        static void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    };
}
#endif //VULKANINSTANCE_H
