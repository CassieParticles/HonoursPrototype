cmake_minimum_required(VERSION 4.1)
project(HonoursPrototype)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(HonoursPrototype main.cpp
        Project/Application.cpp
        Project/Application.h
        Project/GameObjects/TestObject.cpp
        Project/GameObjects/TestObject.h
        Project/MarchingSquares/MarchingSquaresObject.cpp
        Project/MarchingSquares/MarchingSquaresObject.h
        Project/MarchingSquares/VoxelGrid.cpp
        Project/MarchingSquares/VoxelGrid.h
        Project/MarchingSquares/MarchingSquaresRenderable.cpp
        Project/MarchingSquares/MarchingSquaresRenderable.h
        Project/GameObjects/StaticPhysicsFloor.cpp
        Project/GameObjects/StaticPhysicsFloor.h
        Project/GameObjects/DynamicPhysicsBox.cpp
        Project/GameObjects/DynamicPhysicsBox.h
        Project/MarchingSquares/MarchingSquaresPhysics.cpp
        Project/MarchingSquares/MarchingSquaresPhysics.h
        Project/MarchingSquares/Triangle.h
        Project/MarchingSquares/TriangleBuilder.cpp
        Project/MarchingSquares/TriangleBuilder.h
)

add_subdirectory(Engine)
target_include_directories(HonoursPrototype PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Engine)
target_link_libraries(HonoursPrototype PUBLIC HonoursFramework)


target_link_libraries(HonoursPrototype PUBLIC -static)
