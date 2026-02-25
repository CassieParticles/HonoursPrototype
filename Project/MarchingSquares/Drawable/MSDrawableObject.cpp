#include "MSDrawableObject.h"

#include <iostream>
#include <Core/InputHandler.h>

MSDrawableObject::MSDrawableObject(sf::Vector2f mousePosition, sf::Mouse::Button buttonListening):GameObject(),complete(false),buttonListening(buttonListening),physicsStore()
{
    transform.SetPosition(mousePosition);
    grid = new VoxelGrid();
}

MSDrawableObject::MSDrawableObject(sf::Vector2f mousePosition, sf::Mouse::Button buttonListening, VoxelGrid* grid):GameObject(),complete(false),buttonListening(buttonListening),physicsStore()
{
    transform.SetPosition(mousePosition);
    this->grid = grid;
}

MSDrawableObject::~MSDrawableObject()
{
    //If physics existed destroy it (new one is being created)
    if(b2Body_IsValid(physicsStore))
    {
        b2DestroyBody(physicsStore);
    }
}

void MSDrawableObject::TakeInput(InputHandler* input)
{
    if(!input->getMouseButton(buttonListening))
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
