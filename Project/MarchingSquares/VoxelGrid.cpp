#include "VoxelGrid.h"
VoxelGrid::VoxelGrid(): width(0),height(0) {}

VoxelGrid::VoxelGrid(float* data, int width, int height, int x, int y): width(width), height(height), x(x), y(y)
{
    if(data!=nullptr)
    {
        voxelGrid = new float[width * height];
        std::copy(data,data + width * height,voxelGrid);
    }
}

VoxelGrid::~VoxelGrid() {}
float *VoxelGrid::GetData() const {return voxelGrid;}
float VoxelGrid::getVoxel(int x, int y) const {return voxelGrid[y * width + x];}
float& VoxelGrid::operator[](int index) const {return voxelGrid[index];}

void VoxelGrid::AddColumnLeft()
{
    float* newArr = new float[(width + 1) * height];

    //Copy old data (one row at a time)
    for(int row=0;row < height;row++)
    {
        newArr[(row + 1) * width] = 0.0f;
        std::copy(voxelGrid + row * width, voxelGrid + (row + 1) * width, newArr + row * (width + 1) + 1);
    }

    //Overwrite with new array
    delete[] voxelGrid;
    voxelGrid = newArr;

    width++;
}

void VoxelGrid::AddColumnRight()
{
    float* newArr = new float[(width + 1) * height];

    //Copy old data(one row at a time)
    for(int row=0;row<height;row++)
    {
        std::copy(voxelGrid + row * width, voxelGrid + (row + 1) * width, newArr + row * (width + 1));
        newArr[(row + 1) * width - 1] = 0.0f;
    }

    //Overwrite with new array
    delete[] voxelGrid;
    voxelGrid = newArr;

    width++;
}

void VoxelGrid::AddRowTop()
{
    //Create larger array
    float* newArr = new float[width * (height + 1)];

    //Copy old data into array (offset by width)
    std::copy(voxelGrid,voxelGrid + (width * height), newArr + width);

    //Overwrite with new array
    delete[] voxelGrid;
    voxelGrid = newArr;

    height++;
}

void VoxelGrid::AddRowBottom()
{
    //Create larger array
    float* newArr = new float[width * (height + 1)];

    //Copy old data into array
    std::copy(voxelGrid,voxelGrid + (width * height), newArr);

    //Overwrite with new array
    delete[] voxelGrid;
    voxelGrid = newArr;

    height++;
}
