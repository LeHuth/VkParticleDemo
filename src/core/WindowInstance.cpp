//
// Created by leona on 02.05.2025.
//
#include "../../include/core/WindowInstance.h"
#include <vulkan/vulkan.h>
using namespace core;

WindowInstance::WindowInstance(int width, int height)
{
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    m_window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
    glfwSetWindowUserPointer(m_window, this);
    //glfwSetFramebufferSizeCallback(m_window, framebufferResizeCallback);
}

//TODO: Implement Framebuffer resizing
/*void WindowInstance::framebufferResizeCallback(GLFWwindow* window, int width, int height)
{
    auto app = reinterpret_cast<VulkanApp>(glfwGetWindowUserPointer(window));
    app->frameBufferResized = true;
}*/


WindowInstance::~WindowInstance()
{
    if (m_window != nullptr)
    {
        glfwDestroyWindow(m_window);
        m_window = nullptr;
    }
    glfwTerminate();
}
