#include "MSDrawableObject.h"

#include <iostream>
#include <Core/InputHandler.h>

MSDrawableObject::MSDrawableObject(sf::Vector2f mousePosition):GameObject(),complete(false)
{
    transform.SetPosition(mousePosition);
}

MSDrawableObject::~MSDrawableObject() {}

void MSDrawableObject::TakeInput(InputHandler* input)
{
    if(!input->getMouseButton(sf::Mouse::Button::Left))
    {
        std::cout<<"Mouse button released"<<std::endl;
        complete = true;
    }
}

void MSDrawableObject::Update()
{
    GameObject::Update();
}
