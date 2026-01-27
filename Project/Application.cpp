#include "Application.h"

#include <iostream>
#include <Core/Timer.h>

#include "MarchingSquares/VoxelGrid.h"

Application::Application()
{
    PhysicsWorld::CreateWorldBuilder().SetGravity(b2Vec2(0,-10.0f))->Build();
    float data[16] = {
        1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,
        1.0f,0.1f,0.1f,1.0f
    };

    MSObject = new MarchingSquaresObject(data,4,4);

    floorObj.GetTransform().SetPosition(0,3);
    floorObj.GetTransform().SetScale(10,1);

    floorObj.Init();
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
    MSObject->Render(&window);
    floorObj.Render(&window);
}
