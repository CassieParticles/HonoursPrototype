#pragma once
#include <GameObjects/GameObject.h>

#include "../Rendering/TestRenderable.h"

class TestObject:public GameObject
{
public:
    TestObject();

    void Render(sf::RenderWindow* window) override;
protected:
    TestRenderable testRenderable;
};
