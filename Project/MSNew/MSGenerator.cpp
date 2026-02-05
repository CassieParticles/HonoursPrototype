#include "MSGenerator.h"

#include "MSComponent.h"
#include "../MarchingSquares/VoxelGrid.h"

MSGenerator::MSGenerator(VoxelGrid* grid):grid{grid}
{
}

void MSGenerator::AddBuilder(MSTriangleBuilder* builder)
{
    builders.push_back(builder);
}

