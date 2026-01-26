#include "Application.h"

#include <iostream>

#include "MarchingSquares/VoxelGrid.h"

Application::Application()
{
    PhysicsWorld::CreateWorldBuilder().SetGravity(b2Vec2(0,-10.0f))->Build();

    float data[16] = {
        1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f
    };

    VoxelGrid grid{data,4,4};
    grid.PrintValues();
    std::cout<<std::endl;

    grid.AddRowBottom(0.0f);
    grid.PrintValues();
    std::cout<<std::endl;

    grid.AddRowTop(2.0f);
    grid.PrintValues();
    std::cout<<std::endl;

    grid.AddColumnRight(3.0f);
    grid.PrintValues();
    std::cout<<std::endl;

    grid.AddColumnLeft(4.0f);
    grid.PrintValues();
    std::cout<<std::endl;
}
Application::~Application() {}

void Application::Input()
{

}

void Application::Update()
{

}

void Application::Render()
{
    testObject.Render(&window);
}
