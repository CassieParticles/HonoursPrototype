#pragma once
#include <vector>

struct Triangle;

class TriangleBuilder
{
public:
    virtual void AddTriangle(Triangle triangle);

    virtual void Build() = 0;
protected:
    TriangleBuilder();
    std::vector<Triangle> triangles;
};
