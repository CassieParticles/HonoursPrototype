#pragma once

#include <SFML/Graphics.hpp>

#include "../Rendering/Renderable.h"


class GameObject
{
public:
    GameObject();
    virtual ~GameObject();

    virtual void TakeInput() {}
    virtual void Update() {}
    virtual void Render(sf::RenderWindow* window) {renderable->Render(window);}
protected:
    sf::Vector2f position;
    sf::Angle rotation;
    sf::Vector2f scale;

    Renderable* renderable;
};
