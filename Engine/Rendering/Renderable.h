#pragma once
#include <SFML/Graphics.hpp>

#include "../GameObjects/GameObject.h"

class Renderable
{
public:
    Renderable(Transform* transform);
    virtual void Render(sf::RenderWindow* RenderWindow){}
protected:
    Transform* transform;
};
