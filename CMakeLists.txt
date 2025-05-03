cmake_minimum_required(VERSION 3.26)
project(VulkanParticleDemo)

set(CMAKE_CXX_STANDARD 23)

add_executable(VulkanParticleDemo src/main.cpp
        include/app.h
        src/app.cpp
        include/core/VulkanInstance.h
        src/core/VulkanInstance.cpp
        include/utils/DebugUtils.h
        src/utils/DebugUtils.cpp
        include/core/SurfaceInstance.h
        src/core/SurfaceInstance.cpp
        include/core/WindowInstance.h
        src/core/WindowInstance.cpp)

# Find Vulkan
find_package(Vulkan REQUIRED)
if (Vulkan_FOUND)
    message(STATUS "Found Vulkan: ${Vulkan_INCLUDE_DIRS}")
    target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)
else ()
    message(FATAL_ERROR "Vulkan not found")
endif ()

# Manually specify GLM include directory
set(GLM_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/lib/glm") # Update this path to the actual GLM include directory
include_directories(${GLM_INCLUDE_DIR})

if (APPLE)
    find_package(GLFW3 REQUIRED)
    target_link_libraries(${PROJECT_NAME} glfw)
else ()
    set(GLFW_LIBRARY "${CMAKE_SOURCE_DIR}/lib/glfw/lib-vc2022/glfw3.lib")
    target_link_libraries(${PROJECT_NAME} ${GLFW_LIBRARY})
endif ()
# Manually specify GLFW include directory and library
set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/lib/glfw/include") # Update this path to the actual GLFW include directory
#set(GLFW_LIBRARY "${CMAKE_SOURCE_DIR}/lib/glfw/lib-vc2022/glfw3.lib") # Update this path to the actual GLFW library file

include_directories(${GLFW_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${GLFW_LIBRARY})

set(SHADER_SOURCES
        "${CMAKE_SOURCE_DIR}/shaders/*.frag"
        "${CMAKE_SOURCE_DIR}/shaders/*.vert"
)

include("cmake/compileGLSL.cmake")
include("cmake/compileGLSLWin.cmake")
message(STATUS ${PROJECT_NAME})
if (APPLE)
    APPEND_GLSL_TO_TARGET(${PROJECT_NAME})
else ()
    APPEND_GLSL_TO_TARGET_WIN(${PROJECT_NAME})
endif ()