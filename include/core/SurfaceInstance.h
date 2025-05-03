//
// Created by leona on 02.05.2025.
//

#ifndef SURFACEINSTANCE_H
#define SURFACEINSTANCE_H
#include <vulkan/vulkan_core.h>

#include "GLFW/glfw3.h"

namespace core
{
    class SurfaceInstance
    {
    public:
        SurfaceInstance(VkInstance instance, GLFWwindow* window);
        ~SurfaceInstance();

    private:
        VkSurfaceKHR m_surface_khr = VK_NULL_HANDLE;
        VkInstance m_instance_ref = VK_NULL_HANDLE;
    };
}
#endif //SURFACEINSTANCE_H
