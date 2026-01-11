cmake_minimum_required(VERSION 4.1)
project(HonoursPrototype)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(HonoursPrototype main.cpp
        Core/Application.cpp
        Core/Application.h
        Core/InputHandler.cpp
        Core/InputHandler.h
        Rendering/Camera.cpp
        Rendering/Camera.h
        Core/Timer.cpp
        Core/Timer.h
        Rendering/Renderable.cpp
        Rendering/Renderable.h
        Rendering/Camera.cpp
        Rendering/Camera.h
        GameObjects/GameObject.cpp
        GameObjects/GameObject.h)

#SFML
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

target_link_libraries(HonoursPrototype PUBLIC SFML::Graphics)

add_library(Box2D STATIC IMPORTED GLOBAL)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set_property(TARGET Box2D PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/libs/box2d/debug/box2dd.lib")
else()
    set_property(TARGET Box2D PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/libs/box2d/release/box2d.lib")
endif()


target_link_libraries(HonoursPrototype PUBLIC Box2D)

target_link_libraries(HonoursPrototype PUBLIC -static)

target_include_directories(HonoursPrototype PUBLIC libs/includes)