#pragma once
#include <vector>

#include "../MarchingSquares/Triangle.h"

class MSTriangleBuilder
{
public:
    void AddTriangle(Triangle triangle);

    virtual void Build() = 0;
protected:
    MSTriangleBuilder(){}

    std::vector<Triangle> triangles;
};

class MSComponent
{
public:
protected:
};