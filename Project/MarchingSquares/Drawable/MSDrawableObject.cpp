#include "MSDrawableObject.h"

#include <iostream>
#include <Core/InputHandler.h>

MSDrawableObject::MSDrawableObject(sf::Vector2f mousePosition, sf::Mouse::Button buttonListening,float value):GameObject(),complete(false),buttonListening(buttonListening),physicsStore(),value(value)
{
    transform.SetPosition(mousePosition);
    drawRadius = 3.0f;
    grid = new VoxelGrid();
}

MSDrawableObject::MSDrawableObject(sf::Vector2f mousePosition, sf::Mouse::Button buttonListening, VoxelGrid* grid,float value):GameObject(),complete(false),buttonListening(buttonListening),physicsStore(),value(value)
{
    transform.SetPosition(mousePosition);
    drawRadius = 3.0f;
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

    grid->AddValueCircle(input->getMousePositionWorld(),drawRadius,value);
}

void MSDrawableObject::Update()
{

}
