#pragma once
#include <Core/BaseApplication.h>

#include "GameObjects/CameraController.h"
#include "GameObjects/DynamicPhysicsBox.h"
#include "GameObjects/StaticPhysicsFloor.h"
#include "GameObjects/TestObject.h"
#include "MarchingSquares/MarchingSquaresManager.h"
#include "MarchingSquares/MarchingSquaresObject.h"


class Application:public BaseApplication
{
public:
    Application();
    ~Application() override;

protected:
    CameraController controller;

    TestObject testObject;
    MarchingSquaresObject* MSObject;
    std::vector<MarchingSquaresObject*> MSObjects;
    MarchingSquaresManager MSManager;

    StaticPhysicsFloor floorObj;
    StaticPhysicsFloor wallAObj;
    StaticPhysicsFloor wallBObj;
    DynamicPhysicsBox boxObj;

    void Input() override;
    void Update() override;
    void Render() override;
};
