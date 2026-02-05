#pragma once
#include <vector>

#include "../MarchingSquares/VoxelGrid.h"

class MSComponent;
class MSGenerator;

class MSObject
{
public:
    MSObject();

    void SetData(float* data, int width, int height);

    void Generate();
protected:
    VoxelGrid grid;

    MSGenerator* generator;

    std::vector<MSComponent> components;
};
