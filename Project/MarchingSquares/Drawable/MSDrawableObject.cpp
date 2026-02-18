#include "MSDrawableObject.h"

#include <iostream>
#include <Core/InputHandler.h>

MSDrawableObject::MSDrawableObject(sf::Vector2f mousePosition):GameObject(),complete(false)
{
    transform.SetPosition(mousePosition);
    grid = new VoxelGrid();
}

MSDrawableObject::~MSDrawableObject()
{
}

void MSDrawableObject::TakeInput(InputHandler* input)
{
    if(!input->getMouseButton(sf::Mouse::Button::Left))
    {
        std::cout<<"Mouse button released"<<std::endl;
        complete = true;
        return;
    }
    std::cout<<input->getMousePositionWorld().x<<","<<input->getMousePositionWorld().y<<std::endl;

    grid->AddValueCircle(input->getMousePositionWorld(),3,1.0f);
}

void MSDrawableObject::Update()
{
    GameObject::Update();
}
