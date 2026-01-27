#include "Application.h"

#include <iostream>

Application::Application()
{
    PhysicsWorld::CreateWorldBuilder().SetGravity(b2Vec2(0,30.0f))->Build();


    float data[16] = {
        1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,
        1.0f,0.1f,0.1f,1.0f
    };

    MSObject = new MarchingSquaresObject(data,4,4);

    floorObj.GetTransform().SetPosition(-1,8);
    floorObj.GetTransform().SetRotation(sf::degrees(10));
    floorObj.GetTransform().SetScale(10,1);

    floorObj.Init();

    boxObj.GetTransform().SetPosition(0,-5);
    boxObj.Init();
}
Application::~Application() {}

void Application::Input()
{

}

void Application::Update()
{
    boxObj.Update();
}

void Application::Render()
{
    testObject.Render(&window);
    MSObject->Render(&window);

    floorObj.Render(&window);
    boxObj.Render(&window);
}
