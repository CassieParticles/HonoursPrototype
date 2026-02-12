#include "Application.h"

#include <iostream>

Application::Application():controller{&camera}
{
    //Set up controller
    controller.SetMoveSpeed(50);
    controller.SetScrollSpeed(0.001);

    PhysicsWorld::CreateWorldBuilder().SetGravity(b2Vec2(0,30.0f))->Build();

    float data[256] = {
         1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f,
        -0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,
         1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f,
        -0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,
         1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f,
        -0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,
         1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f,
        -0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,
         1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f,
        -0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,
         1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f,
        -0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,
         1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f,
        -0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,
         1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f, 1.0f,-0.1f,
        -0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,-0.1f,
   };


    MarchingSquaresObject* obj = new MarchingSquaresObject();
    obj->SetGrid(data,16,16);
    obj->SetDynamic(true);
    std::vector<MarchingSquaresObject*> objs = obj->Separate();

    for(auto* obj:objs)
    {
        MSObjects.push_back(obj);
        obj->Init();
    }

    //Create box for testing
    floorObj.GetTransform().SetPosition(-1,50);
    floorObj.GetTransform().SetRotation(sf::degrees(10));
    floorObj.GetTransform().SetScale(100,1);

    wallAObj.GetTransform().SetPosition(-50,0);
    wallAObj.GetTransform().SetScale(1,100);

    wallBObj.GetTransform().SetPosition( 50,0);
    wallBObj.GetTransform().SetScale(1,100);

    floorObj.Init();
    wallAObj.Init();
    wallBObj.Init();

    boxObj.GetTransform().SetPosition(5,-2);
    boxObj.Init();
}

Application::~Application()
{
    for(auto* obj : MSObjects)
    {
        delete obj;
    }
}

void Application::Input()
{
    controller.TakeInput(&input);
}

void Application::Update()
{
    controller.Update();

    boxObj.Update();
    wallAObj.Update();
    wallBObj.Update();

    for(auto* obj : MSObjects)
    {
        obj->Update();
    }
}

void Application::Render()
{
    for(auto* obj : MSObjects)
    {
        obj->Render(&window);
    }

    floorObj.Render(&window);
    wallAObj.Render(&window);
    wallBObj.Render(&window);
    boxObj.Render(&window);
}

