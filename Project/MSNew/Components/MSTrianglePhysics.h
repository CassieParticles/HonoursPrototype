#pragma once
#include <box2d/box2d.h>

#include "../MSComponent.h"


class Transform;

class MSTrianglePhysics: MSComponent
{
public:
    explicit MSTrianglePhysics(Transform* transform);

    void Update();

    class MSTrianglePhysicsBuilder: public MSTriangleBuilder
    {
        friend class MSTrianglePhysics;
    public:
        MSTrianglePhysicsBuilder* SetDynamic(bool isDynamic){this->isDynamic = isDynamic; return this;}

        void Build() override;

    protected:
        MSTrianglePhysicsBuilder(MSTrianglePhysics* physics);
        MSTrianglePhysics* physics;

        bool isDynamic;
    };
    MSTrianglePhysicsBuilder GetBuilder(){return {this};}
protected:
    Transform* transform;

    b2BodyId bodyId;
    std::vector<b2ShapeId> shapes;
};
