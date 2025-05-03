//
// Created by leona on 02.05.2025.
//
#include "../../include/core/SurfaceInstance.h"

#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

using namespace core;


SurfaceInstance::SurfaceInstance(VkInstance instance, GLFWwindow* window) : m_instance_ref(instance)
{
    if (instance == VK_NULL_HANDLE)
    {
        throw std::runtime_error("Vulkan instance is null!");
    }
    if (window == nullptr)
    {
        throw std::runtime_error("GLFW window is null!");
    }
    VkResult result = glfwCreateWindowSurface(instance, window, nullptr, &m_surface_khr); // Store result
    if (result != VK_SUCCESS)
    {
        // Include the result code in the error message
        throw std::runtime_error("failed to create window surface! VkResult: " + std::to_string(result));
    }
}

SurfaceInstance::~SurfaceInstance()
{
    if (m_surface_khr != VK_NULL_HANDLE)
    {
        vkDestroySurfaceKHR(m_instance_ref, m_surface_khr, nullptr);
        m_surface_khr = VK_NULL_HANDLE;
    }
}
