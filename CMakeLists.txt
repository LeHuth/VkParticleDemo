cmake_minimum_required(VERSION 3.26)
project(VulkanParticleDemo)

set(CMAKE_CXX_STANDARD 23)

add_executable(VulkanParticleDemo src/main.cpp)

# Find Vulkan
find_package(Vulkan REQUIRED)
if (Vulkan_FOUND)
    message(STATUS "Found Vulkan: ${Vulkan_INCLUDE_DIRS}")
    target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)
else()
    message(FATAL_ERROR "Vulkan not found")
endif()

# Manually specify GLM include directory
set(GLM_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/lib/glm") # Update this path to the actual GLM include directory
include_directories(${GLM_INCLUDE_DIR})

# Manually specify GLFW include directory and library
set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/lib/glfw/include") # Update this path to the actual GLFW include directory
set(GLFW_LIBRARY "${CMAKE_SOURCE_DIR}/lib/glfw/lib-vc2022/glfw3.lib") # Update this path to the actual GLFW library file

include_directories(${GLFW_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${GLFW_LIBRARY})