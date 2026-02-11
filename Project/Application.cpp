#include "Application.h"

#include <iostream>

Application::Application()
{
    PhysicsWorld::CreateWorldBuilder().SetGravity(b2Vec2(0,30.0f))->Build();

    float data[64] = {
        -1.0f,-1.0f,-1.0f,-1.0f,-1.0f,-1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,-1.0f, 1.0f,-1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,-1.0f, 1.0f,-1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,-1.0f, 1.0f,-1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,-1.0f, 1.0f,-1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,-1.0f, 1.0f,-1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,-1.0f, 1.0f,-1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,-1.0f,-1.0f,-1.0f,-1.0f,-1.0f,
    };

    VoxelGrid* voxelGridOriginal = new VoxelGrid(data,8,8);
    voxelGridOriginal->AddBorder(-1);
    voxelGridOriginal->PrintValues();
    std::cout<<"======================================\n";
    std::vector<VoxelGrid*> newGrids = voxelGridOriginal->GetSubgrids();
    for(auto* grid:newGrids)
    {
        grid->PrintValues();
        std::cout<<"======================================\n";
    }


    MarchingSquaresObject* obj = new MarchingSquaresObject();
    obj->SetGrid(data,8,8);
    obj->SetDynamic(true);
    std::vector<MarchingSquaresObject*> objs = obj->Separate();

    for(auto* obj:objs)
    {
        MSObjects.push_back(obj);
        obj->Init();
    }

    // for(auto* obj:MSObjects)
    // {
    //     obj->Init();
    // }

    //Create box for testing
    floorObj.GetTransform().SetPosition(-1,10);
    floorObj.GetTransform().SetRotation(sf::degrees(10));
    floorObj.GetTransform().SetScale(20,1);

    wallAObj.GetTransform().SetPosition(-10,0);
    wallAObj.GetTransform().SetScale(1,20);

    wallBObj.GetTransform().SetPosition( 10,0);
    wallBObj.GetTransform().SetScale(1,20);

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

}

void Application::Update()
{
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

