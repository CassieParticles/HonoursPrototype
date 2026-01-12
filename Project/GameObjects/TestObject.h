#pragma once
#include <GameObjects/GameObject.h>
#include <Rendering/ColourBoxRenderable.h>

class TestObject:public GameObject
{
public:
    TestObject();

    void Render(sf::RenderWindow* window) override;
protected:
    ColourBoxRenderable colourRenderable;
};
