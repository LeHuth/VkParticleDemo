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

        static constexpr bool enableValidationLayers =
#ifdef NDEBUG
false;
#else
    true;
#endif

    private:
    VkInstance m_instance;
    };

}
#endif //VULKANINSTANCE_H
