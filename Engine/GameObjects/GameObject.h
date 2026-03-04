#pragma once

#include <SFML/Graphics.hpp>

#include "Transform.h"


class InputHandler;

class GameObject
{
public:
    GameObject();
    virtual ~GameObject();

    Transform& GetTransform(){return transform;}
    void SetTransform(const Transform& transform){this->transform.SetData(transform);}

    virtual void Init() {}

    virtual void TakeInput(InputHandler* input) {}
    virtual void Update() {}
    virtual void Render(sf::RenderWindow* window) {}
protected:
    Transform transform;
};
