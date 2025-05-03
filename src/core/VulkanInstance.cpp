//
// Created by Leo on 30.04.25.
//
#include "../../include/core/VulkanInstance.h"

#include <iostream>
#include <ostream>

#include "../../include/utils/DebugUtils.h"

#include <stdexcept>

using namespace core;

VulkanInstance::VulkanInstance()
{
    if (utils::DebugUtils::enableValidationLayers && !utils::DebugUtils::checkValidationLayerSupport())
    {
        throw std::runtime_error("validation layers requested, but not available!");
    }

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    auto extensions = utils::DebugUtils::getRequiredExtensions();

    // Check if the platform is Apple and enable VK_KHR_portability_enumeration extension
    if (utils::DebugUtils::isMacOS())
    {
        // You can implement this helper function to check macOS
        extensions.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
        extensions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
    }

    createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    createInfo.ppEnabledExtensionNames = extensions.data();


    VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
    if (utils::DebugUtils::enableValidationLayers)
    {
        createInfo.enabledLayerCount = static_cast<uint32_t>(utils::validationLayers.size());
        createInfo.ppEnabledLayerNames = utils::validationLayers.data();

        utils::DebugUtils::populateDebugMessengerCreateInfo(debugCreateInfo);
        createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
    }
    else
    {
        createInfo.enabledLayerCount = 0;
        createInfo.pNext = nullptr;
    }

    // Set the flag to enable portability on macOS
    if (utils::DebugUtils::isMacOS())
    {
        std::cout << "macOS detected, enabling VK_KHR_portability_enumeration extension" << std::endl;
        createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
    }

    if (vkCreateInstance(&createInfo, nullptr, &m_instance) != VK_SUCCESS)
    {
        throw std::runtime_error("failed to create instance!");
    }
    std::cout << "Vulkan instance created successfully!" << std::endl;
}

VkInstance& VulkanInstance::getInstance()
{
    return m_instance;
}

VulkanInstance::~VulkanInstance()
{
    vkDestroyInstance(m_instance, nullptr);
}


