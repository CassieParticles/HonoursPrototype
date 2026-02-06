#pragma once
#include "../MSGenerator.h"

class MSBasicGenerator: public MSGenerator
{
public:
    explicit MSBasicGenerator(VoxelGrid* grid): MSGenerator(grid) {}

    void Generate() override;
};
