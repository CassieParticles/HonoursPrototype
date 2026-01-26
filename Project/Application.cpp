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
    MSObject->GetTransform().SetPosition(sf::Vector2f(5.0f,0.0f));
    MSObject->GetTransform().SetScale(sf::Vector2f(0.2f,0.2f));
}
Application::~Application() {}

void Application::Input()
{

}

void Application::Update()
{
    MSObject->GetTransform().SetRotation(sf::radians(Timer::getElapsedTime()));
}

void Application::Render()
{
    testObject.Render(&window);
    MSObject->Render(&window);
}
