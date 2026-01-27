#pragma once
#include <Core/BaseApplication.h>
#include <GameObjects/GameObject.h>

#include "GameObjects/StaticPhysicsFloor.h"
#include "GameObjects/TestObject.h"
#include "MarchingSquares/MarchingSquaresObject.h"


class Application:public BaseApplication
{
public:
    Application();
    ~Application() override;

protected:
    TestObject testObject;
    MarchingSquaresObject* MSObject;
    float data[16] = {
        1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f
    };

    StaticPhysicsFloor floorObj;



    void Input() override;
    void Update() override;
    void Render() override;
};
