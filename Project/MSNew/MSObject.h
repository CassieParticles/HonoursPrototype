#pragma once
#include <vector>

#include "../MarchingSquares/VoxelGrid.h"
#include "Components/MSTrianglePhysics.h"
#include "Components/MSTriangleRenderer.h"

class MSGenerator;

class MSObject: public GameObject
{
public:
    MSObject();
    void SetData(float* data, int width, int height);
    void Generate();

    void Update() override;
    void Render(sf::RenderWindow* window) override;

protected:
    VoxelGrid grid;

    MSGenerator* generator;

    MSTrianglePhysics physics;
    MSTriangleRenderer renderer;
};
