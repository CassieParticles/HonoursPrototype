#pragma once
#include <Core/BaseApplication.h>
#include <GameObjects/GameObject.h>

#include "GameObjects/DynamicPhysicsBox.h"
#include "GameObjects/StaticPhysicsFloor.h"
#include "GameObjects/TestObject.h"
#include "MarchingSquares/MarchingSquaresObject.h"
#include "MSNew/MSObject.h"


class Application:public BaseApplication
{
public:
    Application();
    ~Application() override;

protected:
    TestObject testObject;
    //MarchingSquaresObject* MSObject;

    MSObject msObject;

    StaticPhysicsFloor floorObj;
    DynamicPhysicsBox boxObj;

    void Input() override;
    void Update() override;
    void Render() override;
};
