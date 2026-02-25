#pragma once
#include <vector>
#include <box2d/box2d.h>
#include <GameObjects/Transform.h>

#include "../TriangleBuilder.h"

class MarchingSquaresPhysics
{
public:
    MarchingSquaresPhysics(Transform* transform);
    ~MarchingSquaresPhysics();

    class MSPhysicsBuilder: public TriangleBuilder
    {
        friend class MarchingSquaresPhysics;
    public:
        void SetDynamic(bool isDynamic);

        void Build() override;
    protected:
        MSPhysicsBuilder(MarchingSquaresPhysics* object);
        MarchingSquaresPhysics* object;

        bool isDynamic;
    };

    void MarkShouldntDestroy(){shouldntDestroy = true;}
    b2BodyId getBody(){return bodyId;}

    MSPhysicsBuilder GetBuilder();
    void Update();
private:
    Transform* transform;

    b2BodyId bodyId;
    std::vector<b2ShapeId> shapes;

    bool shouldntDestroy;
};


