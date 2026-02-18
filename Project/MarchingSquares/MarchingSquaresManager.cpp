#include "MarchingSquaresManager.h"

#include <Core/InputHandler.h>
#include "Object/MarchingSquaresObject.h"
#include "Drawable/MSDrawableObject.h"

MarchingSquaresManager::MarchingSquaresManager():mousePressed{false}
{

}
MarchingSquaresManager::~MarchingSquaresManager()
{
    for(auto* obj : MSObjects)
    {
        delete obj;
    }
}

void MarchingSquaresManager::Add(float* data, int width, int height, bool dynamic)
{
    MarchingSquaresObject* obj = new MarchingSquaresObject();
    obj->SetGrid(data,width,height);
    obj->SetDynamic(dynamic);

    std::vector<MarchingSquaresObject*> objects = obj->Separate();
    for(auto* obj:objects)
    {
        obj->Init();
        MSObjects.push_back(obj);
    }
}

void MarchingSquaresManager::TakeInput(InputHandler* inputHandler)
{
    if(inputHandler->getMouseButton(sf::Mouse::Button::Left) && !mousePressed)
    {
        //Create new drawable
        MSDrawableObject* drawable = new MSDrawableObject(sf::Vector2f(0,0));
        MSDrawables.push_back(drawable);
        mousePressed = true;
    }
    else if(!inputHandler->getMouseButton(sf::Mouse::Button::Left))
    {
        mousePressed = false;
    }
    for(auto* obj : MSDrawables)
    {
        obj->TakeInput(inputHandler);
    }
}

void MarchingSquaresManager::Update()
{
    //Update and clear empty objects
    for(auto it = MSObjects.begin();it!=MSObjects.end();)
    {
        auto* obj = (*it);
        if(obj->GetTriangleCount()==0)
        {
            delete obj;
            it = MSObjects.erase(it);
            continue;
        }
        obj->Update();
        ++it;
    }

    for(auto it = MSDrawables.begin();it!=MSDrawables.end();)
    {
        auto* obj = (*it);
        if(obj->isComplete())
        {
            delete obj;
            it=MSDrawables.erase(it);
            continue;
        }
        obj->Update();
        ++it;
    }
}

void MarchingSquaresManager::Render(sf::RenderWindow* window)
{
    for(auto* obj: MSObjects)
    {
        obj->Render(window);
    }
}
