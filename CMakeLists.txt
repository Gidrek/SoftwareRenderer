cmake_minimum_required(VERSION 3.15)
project(3drenderer C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)

add_executable(3drenderer
    src/main.c
    src/game.h
    src/gidreklib/renderer.h
    src/gidreklib/renderer.c
    src/game.c
)

target_include_directories(3drenderer PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(3drenderer PRIVATE SDL2::SDL2)

message(STATUS "Ruta de include encontrada: ${SDL2_INCLUDE_DIR}")
message(STATUS "Ruta de SDL2.lib encontrada: ${SDL2_LIBRARY}")
message(STATUS "Ruta de SDL2main.lib encontrada: ${SDL2MAIN_LIBRARY}")

if(WIN32 AND SDL2_DLL_PATH)
    add_custom_command(TARGET 3drenderer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_DLL_PATH}"
        "$<TARGET_FILE_DIR:3drenderer>"
    )
endif()