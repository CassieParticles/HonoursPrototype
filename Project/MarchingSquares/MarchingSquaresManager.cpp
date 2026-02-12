#include "MarchingSquaresManager.h"
MarchingSquaresManager::MarchingSquaresManager() {}
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

void MarchingSquaresManager::Update()
{
    std::vector<MarchingSquaresObject*>::iterator it = MSObjects.begin();
    while(it!=MSObjects.end())
    {
        auto* obj = (*it);
        if(obj->GetTriangleCount()==4)
        {
            delete obj;
            it = MSObjects.erase(it);
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
