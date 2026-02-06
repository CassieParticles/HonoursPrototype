#include "TriangleBuilder.h"

#include "Triangle.h"

void TriangleBuilder::AddTriangle(Triangle triangle)
{
    triangles.push_back(triangle);
}

TriangleBuilder::TriangleBuilder() = default;
