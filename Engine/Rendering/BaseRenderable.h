#pragma once
#include <SFML/Graphics.hpp>

#include "../GameObjects/GameObject.h"

class BaseRenderable
{
public:
    BaseRenderable(Transform* transform);
    virtual void Render(sf::RenderWindow* RenderWindow){}
protected:
    Transform* transform;
};
