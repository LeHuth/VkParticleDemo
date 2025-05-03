//
// Created by leona on 02.05.2025.
//

#ifndef WINDOWINSTANCE_H
#define WINDOWINSTANCE_H
#include <vulkan/vulkan_core.h>
#include "GLFW/glfw3.h"

namespace core
{
    class WindowInstance
    {
    public:
        WindowInstance(int width, int height);
        ~WindowInstance();

        [[nodiscard]] GLFWwindow* getWindow() { return m_window; }

        //static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

    private:
        GLFWwindow* m_window = nullptr;
        const int WIDTH = 800;
        const int HEIGHT = 600;
    };
}
#endif //WINDOWINSTANCE_H
