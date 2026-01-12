#pragma once
#include <box2d/box2d.h>

#include "../GameObjects/Transform.h"

class Rigidbody
{
    friend class BodyBuilder;
public:
    Rigidbody();
    ~Rigidbody();

    class BodyBuilder
    {
        friend class Rigidbody;
    public:
        BodyBuilder* SetTransform(Transform transform);
        BodyBuilder* SetVelocity(sf::Vector2f linearVelocity);
        BodyBuilder* SetType(b2BodyType type);

        void Build();
    protected:
        BodyBuilder(Rigidbody* rigidbody);
        b2BodyDef bodyDef;
        Rigidbody* rigidbody;
    };
    BodyBuilder CreateBodyBuilder();
protected:
    b2BodyId bodyId;
};
