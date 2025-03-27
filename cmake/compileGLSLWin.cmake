


macro(APPEND_GLSL_TO_TARGET_WIN target)
    set(GLSL_VALIDATOR glslangValidator.exe)
    message(STATUS "APPENDING GLSL WIN TO TARGET")
    file(GLOB_RECURSE GLSL_SOURCE_FILES
            "shaders/*.frag"
            "shaders/*.vert"
    )
    set(PROJECT_BINARY_DIR "${CMAKE_BINARY_DIR}")
    set(SPIRV_BINARY_FILES)

    foreach(GLSL ${GLSL_SOURCE_FILES})
        get_filename_component(FILE_NAME ${GLSL} NAME_WE)
        set(SPIRV "${PROJECT_BINARY_DIR}/shaders/${FILE_NAME}.spv")
        add_custom_command(
                OUTPUT ${SPIRV}
                COMMAND ${CMAKE_COMMAND} -E make_directory "${PROJECT_BINARY_DIR}/shaders/"
                COMMAND ${GLSL_VALIDATOR} -V ${GLSL} -o ${SPIRV}
                DEPENDS ${GLSL}
        )
        list(APPEND SPIRV_BINARY_FILES ${SPIRV})
    endforeach()

    add_custom_target(
            Shaders
            DEPENDS ${SPIRV_BINARY_FILES}
    )
    add_dependencies(${target} Shaders)

    add_custom_command(TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${target}>/shaders/"
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${PROJECT_BINARY_DIR}/shaders"
            "$<TARGET_FILE_DIR:${target}>/shaders"
    )
endmacro()