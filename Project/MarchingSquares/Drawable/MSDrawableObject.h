#pragma once
#include <GameObjects/GameObject.h>

#include "../VoxelGrid.h"


class MSDrawableObject: public GameObject
{
public:
    MSDrawableObject(sf::Vector2f mousePosition);
    ~MSDrawableObject();

    void TakeInput(InputHandler* input) override;

    void Update() override;

    bool isComplete() const { return complete; }
    VoxelGrid* getGrid(){return grid;}

private:
    VoxelGrid* grid;

    float drawRadius;

    bool complete;
};
