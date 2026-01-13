#pragma once
#include <box2d/box2d.h>
#include <vector>

#include "../GameObjects/Transform.h"

class Rigidbody
{
    friend class BodyBuilder;
    friend class ShapeBuilder;
public:
    Rigidbody(Transform* transform);
    ~Rigidbody();

    class BodyBuilder
    {
        friend class Rigidbody;
    public:
        BodyBuilder* SetVelocity(sf::Vector2f linearVelocity);
        BodyBuilder* SetType(b2BodyType type);

        void Build();
    protected:
        //Internally called by rigidbody
        BodyBuilder* SetTransform(Transform* transform);

        BodyBuilder(Rigidbody* rigidbody);
        b2BodyDef bodyDef;
        Rigidbody* rigidbody;
    };
    BodyBuilder CreateBodyBuilder();
    ShapeBuilder CreateShapeBuilder();
protected:
    Transform* transform;
    b2BodyId bodyId;
    std::vector<b2ShapeId> attachedShapes;
};
