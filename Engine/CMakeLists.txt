cmake_minimum_required(VERSION 4.1)

add_library(HonoursFramework STATIC
        Core/BaseApplication.cpp
        Core/BaseApplication.h
        Core/InputHandler.cpp
        Core/InputHandler.h
        Rendering/Camera.cpp
        Rendering/Camera.h
        Core/Timer.cpp
        Core/Timer.h
        Rendering/BaseRenderable.cpp
        Rendering/BaseRenderable.h
        Rendering/Camera.cpp
        Rendering/Camera.h
        GameObjects/GameObject.cpp
        GameObjects/GameObject.h
        GameObjects/Transform.cpp
        GameObjects/Transform.h
        Rendering/ColourBoxRenderable.cpp
        Rendering/ColourBoxRenderable.h
        Physics/PhysicsWorld.cpp
        Physics/PhysicsWorld.h
        Physics/Rigidbody.cpp
        Physics/Rigidbody.h
        )

#SFML
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

target_link_libraries(HonoursFramework PUBLIC SFML::Graphics)


#Box2D
add_library(Box2D STATIC IMPORTED GLOBAL)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
        set_property(TARGET Box2D PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/libs/box2d/debug/box2dd.lib")
else()
        set_property(TARGET Box2D PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/libs/box2d/release/box2d.lib")
endif()

target_link_libraries(HonoursFramework PUBLIC Box2D)
target_include_directories(HonoursFramework PUBLIC libs/includes)