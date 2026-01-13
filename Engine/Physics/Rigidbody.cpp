#include "Rigidbody.h"

#include "PhysicsWorld.h"
#include "ShapeBuilder.h"


Rigidbody::Rigidbody(Transform* transform):transform{transform} {}
Rigidbody::~Rigidbody() {}

Rigidbody::BodyBuilder Rigidbody::CreateBodyBuilder()
{
    return {this};
}

ShapeBuilder Rigidbody::CreateShapeBuilder()
{
    return {this};
}

Rigidbody::BodyBuilder* Rigidbody::BodyBuilder::SetTransform(Transform* transform)
{
    bodyDef.position = b2Vec2(transform->GetPosition().x, transform->GetPosition().y);
    float angle = transform->GetRotation().asRadians();
    bodyDef.rotation = b2MakeRot(angle);
    return this;
}


Rigidbody::BodyBuilder* Rigidbody::BodyBuilder::SetVelocity(sf::Vector2f linearVelocity)
{
    bodyDef.linearVelocity.x = linearVelocity.x;
    bodyDef.linearVelocity.y = linearVelocity.y;
    return this;
}

Rigidbody::BodyBuilder* Rigidbody::BodyBuilder::SetType(b2BodyType type)
{
    bodyDef.type = type;
    return this;
}

void Rigidbody::BodyBuilder::Build()
{
    SetTransform(rigidbody->transform);
    rigidbody->bodyId = b2CreateBody(PhysicsWorld::worldId,&bodyDef);
}

Rigidbody::BodyBuilder::BodyBuilder(Rigidbody* rigidbody)
{
    bodyDef = b2DefaultBodyDef();
}
