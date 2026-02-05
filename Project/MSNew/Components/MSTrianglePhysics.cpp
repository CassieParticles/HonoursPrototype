#include "MSTrianglePhysics.h"

#include <box2d/box2d.h>
#include <GameObjects/Transform.h>
#include <Physics/PhysicsWorld.h>

MSTrianglePhysics::MSTrianglePhysics(Transform* transform):transform{transform} {}

void MSTrianglePhysics::Update() {
    b2Vec2 position = b2Body_GetPosition(bodyId);
    b2Rot rotation = b2Body_GetRotation(bodyId);

    transform->SetPosition(position);
    transform->SetRotation(rotation);
}

void MSTrianglePhysics::MSTrianglePhysicsBuilder::Build()
{
    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.position = physics->transform->GetPositionb2();
    bodyDef.rotation = physics->transform->GetRotationb2();

    bodyDef.type = isDynamic ? b2_dynamicBody : b2_staticBody;
    physics->bodyId = b2CreateBody(PhysicsWorld::GetWorldId(),&bodyDef);

    b2ShapeDef shapeDef = b2DefaultShapeDef();

    for(auto triangle : triangles)
    {
        b2Vec2 points[3]
        {
            {triangle.A.x,triangle.A.y},
            {triangle.B.x,triangle.B.y},
            {triangle.C.x,triangle.C.y}
        };

        b2Hull hull = b2ComputeHull(points,3);
        b2Polygon polygon = b2MakePolygon(&hull,0);

        physics->shapes.push_back(b2CreatePolygonShape(physics->bodyId,&shapeDef,&polygon));
    }
}
MSTrianglePhysics::MSTrianglePhysicsBuilder::MSTrianglePhysicsBuilder(MSTrianglePhysics* physics):physics{physics} {}
