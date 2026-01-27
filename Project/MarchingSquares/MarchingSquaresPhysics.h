#pragma once
#include <vector>
#include <box2d/box2d.h>
#include <GameObjects/Transform.h>

#include "Triangle.h"

class MarchingSquaresPhysics
{
public:
    MarchingSquaresPhysics(Transform* transform);

    class MSPhysicsBuilder
    {
        friend class MarchingSquaresPhysics;
    public:
        void AddTriangle(Triangle triangle);
        void SetDynamic(bool isDynamic);

        void Build();
    private:
        MSPhysicsBuilder(MarchingSquaresPhysics* object);
        MarchingSquaresPhysics* object;

        std::vector<Triangle> triangles;
        bool isDynamic;
    };

    MSPhysicsBuilder GetBuilder();
private:
    Transform* transform;

    b2BodyId bodyId;
    std::vector<b2ShapeId> shapes;

    void Update();
};


