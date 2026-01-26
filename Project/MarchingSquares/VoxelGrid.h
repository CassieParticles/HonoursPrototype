#pragma once
#include <vector>

class VoxelGrid
{
public:
    VoxelGrid();
    VoxelGrid(float* data, int width, int height, int x=0, int y=0);

    ~VoxelGrid();

    float *GetData() const;

    //Read values from the grid
    float getVoxel(int x, int y) const;
    float& operator[](int index) const;

    void PrintValues();
private:
    void AddColumnLeft();
    void AddColumnRight();
    void AddRowTop();
    void AddRowBottom();

    float* voxelGrid;

    //Width and height of the grid
    int width;
    int height;

    //Local position of top left corner
    int x;
    int y;
};
