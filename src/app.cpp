#include "../include/app.h"

#include <stdexcept>
//
// Created by Leo on 02.04.25.
//
using namespace sph;

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

void VkApp::run()
{
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void VkApp::initWindow()
{
}

void VkApp::initVulkan()
{
    createInstance();
    //setupDebugMessenger();
    /*createSurface();
    pickPhysicalDevice();
    createLogicalDevice();
    createSwapChain();
    createImageViews();
    createRenderPass();
    createGraphicsPipeline();
    createFramebuffers();
    createCommandPool();
    createCommandBuffer();
    createSyncObjects();*/
}

void VkApp::mainLoop()
{
}

void VkApp::cleanup()
{
}

void VkApp::createInstance()
{
    if (enableValidationLayers && !checkValidationLayerSupport())
    {
        throw std::runtime_error("validation layers requested, but not available!");
    }
}


// =============== Helper Methods ===============

bool VkApp::checkValidationLayerSupport()
{
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

    for (const char* layerName : validationLayers)
    {
        bool layerFound = false;

        for (const auto& layerProperties : availableLayers)
        {
            if (strcmp(layerName, layerProperties.layerName) == 0)
            {
                layerFound = true;
                break;
            }
        }

        if (!layerFound)
        {
            return false;
        }
    }

    return true;
}

std::vector<const char*> VkApp::getRequiredExtensions()
{
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

    if (enableValidationLayers)
    {
        extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    }


    return extensions;
}
