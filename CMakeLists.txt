cmake_minimum_required(VERSION 3.31)
project(3drenderer C)

set(CMAKE_C_STANDARD 99)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)

add_executable(3drenderer src/main.c
        src/game.h
        src/gidreklib/renderer.h)

target_include_directories(3drenderer PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(3drenderer PRIVATE ${SDL2_LIBRARIES})

# On Windows, copy SDL2.dll next to the executable automatically (optional)
if (WIN32)
    add_custom_command(TARGET 3drenderer POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SDL2_DIR}/bin/SDL2.dll"
            $<TARGET_FILE_DIR:3drenderer>)
endif()