#include "DynamicPhysicsBox.h"

#include <Physics/PhysicsWorld.h>
DynamicPhysicsBox::DynamicPhysicsBox():GameObject(),renderable(&transform,sf::Color::Green) {}

void DynamicPhysicsBox::Init()
{
    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = transform.GetPositionb2();
    bodyDef.rotation = transform.GetRotationb2();

    bodyDef.userData = this;

    bodyId = b2CreateBody(PhysicsWorld::GetWorldId(),&bodyDef);

    b2ShapeDef shapeDef = b2DefaultShapeDef();

    b2Vec2 size = transform.GetScaleb2();
    b2Polygon box = b2MakeBox(size.x/2,size.y/2);

    b2CreatePolygonShape(bodyId,&shapeDef, &box);
}

void DynamicPhysicsBox::Update()
{
    b2Vec2 bodyPos = b2Body_GetPosition(bodyId);
    b2Rot bodyRot = b2Body_GetRotation(bodyId);

    transform.SetPosition(bodyPos);
    transform.SetRotation(bodyRot);
}

void DynamicPhysicsBox::Render(sf::RenderWindow* window)
{
    renderable.Render(window);
}
