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

    int getWidth() const {return width;}
    int getHeight() const {return height;}

    void PrintValues();
    void AddBorder(float defaultValue = 0.0f);
private:
    void AddColumnLeft(float defaultValue = 0.0f);
    void AddColumnRight(float defaultValue = 0.0f);
    void AddRowTop(float defaultValue = 0.0f);
    void AddRowBottom(float defaultValue = 0.0f);

    float* voxelGrid;

    //Width and height of the grid
    int width;
    int height;

    //Local position of top left corner
    int x;
    int y;
};
