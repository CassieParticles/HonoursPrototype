#include "VoxelGrid.h"

#include <iostream>
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

void VoxelGrid::PrintValues()
{
    for(int i=0;i<height;++i)
    {
        std::cout<<"[";
        for(int j=0;j<width;++j)
        {
            std::cout<<voxelGrid[i * width + j];
            if(j + 1 != width) { std::cout<<", "; }
        }
        std::cout<<"]"<<std::endl;
    }
}

void VoxelGrid::AddBorder(float defaultValue)
{
    AddColumnLeft(defaultValue);
    AddColumnRight(defaultValue);
    AddRowTop(defaultValue);
    AddRowBottom(defaultValue);
}

void VoxelGrid::AddColumnLeft(float defaultValue)
{
    float* newArr = new float[(width + 1) * height];

    //Copy old data (one row at a time)
    for(int row=0;row < height;row++)
    {
        newArr[row * (width + 1)] = defaultValue;
        //Set default value in new space
        std::copy(voxelGrid + row * width, voxelGrid + (row + 1) * width, newArr + row * (width + 1) + 1);
    }

    //Overwrite with new array
    delete[] voxelGrid;
    voxelGrid = newArr;

    width++;
    x--;
}

void VoxelGrid::AddColumnRight(float defaultValue)
{
    float* newArr = new float[(width + 1) * height];

    //Copy old data(one row at a time)
    for(int row=0;row<height;row++)
    {
        std::copy(voxelGrid + row * width, voxelGrid + (row + 1) * width, newArr + row * (width + 1));
        //Set default value in new space
        newArr[(row + 1) * (width + 1) - 1] = defaultValue;
    }

    //Overwrite with new array
    delete[] voxelGrid;
    voxelGrid = newArr;

    width++;
}

void VoxelGrid::AddRowTop(float defaultValue)
{
    //Create larger array
    float* newArr = new float[width * (height + 1)];

    //Copy old data into array (offset by width)
    std::copy(voxelGrid,voxelGrid + (width * height), newArr + width);

    //Set default valuein new space
    for(int i=0;i<width;++i)
    {
        newArr[i] = defaultValue;
    }

    //Overwrite with new array
    delete[] voxelGrid;
    voxelGrid = newArr;

    height++;
    y--;
}

void VoxelGrid::AddRowBottom(float defaultValue)
{
    //Create larger array
    float* newArr = new float[width * (height + 1)];

    //Copy old data into array
    std::copy(voxelGrid,voxelGrid + (width * height), newArr);

    //Set default value in new space
    for(int i=0;i<width;++i)
    {
        newArr[width * height + i] = defaultValue;
    }

    //Overwrite with new array
    delete[] voxelGrid;
    voxelGrid = newArr;

    height++;
}
