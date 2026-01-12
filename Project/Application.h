#pragma once
#include <Core/BaseApplication.h>
#include <GameObjects/GameObject.h>

#include "GameObjects/TestObject.h"


class Application:public BaseApplication
{
public:
    Application();
    ~Application() override;

protected:
    TestObject testObject;




    void Input() override;
    void Update() override;
    void Render() override;
};
