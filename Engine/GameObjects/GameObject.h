#pragma once

#include <SFML/Graphics.hpp>

#include "Transform.h"
#include "../Rendering/BaseRenderable.h"


class GameObject
{
public:
    GameObject();
    virtual ~GameObject();

    Transform& GetTransform(){return transform;}

    virtual void TakeInput() {}
    virtual void Update() {}
    virtual void Render(sf::RenderWindow* window) {}
protected:
    Transform transform;
};
