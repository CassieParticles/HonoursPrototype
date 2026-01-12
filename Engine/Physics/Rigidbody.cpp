#include "Rigidbody.h"

#include "PhysicsWorld.h"

Rigidbody::Rigidbody() {}

Rigidbody::~Rigidbody() {}

Rigidbody::BodyBuilder Rigidbody::CreateBodyBuilder()
{
    return {this};
}

Rigidbody::BodyBuilder* Rigidbody::BodyBuilder::SetTransform(Transform transform)
{
    bodyDef.position = b2Vec2(transform.GetPosition().x, transform.GetPosition().y);
    float angle = transform.GetRotation().asRadians();
    bodyDef.rotation = b2MakeRot(angle);
}


Rigidbody::BodyBuilder* Rigidbody::BodyBuilder::SetVelocity(sf::Vector2f linearVelocity)
{
    bodyDef.linearVelocity.x = linearVelocity.x;
    bodyDef.linearVelocity.y = linearVelocity.y;
}

Rigidbody::BodyBuilder* Rigidbody::BodyBuilder::SetType(b2BodyType type)
{
    bodyDef.type = type;
}

void Rigidbody::BodyBuilder::Build() {rigidbody->bodyId = b2CreateBody(PhysicsWorld::worldId,&bodyDef);}

Rigidbody::BodyBuilder::BodyBuilder(Rigidbody* rigidbody)
{
    bodyDef = b2DefaultBodyDef();
}
