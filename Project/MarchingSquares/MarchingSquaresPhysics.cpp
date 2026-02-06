#include "MarchingSquaresPhysics.h"

#include <Physics/PhysicsWorld.h>

#include "Triangle.h"

MarchingSquaresPhysics::MarchingSquaresPhysics(Transform* transform):transform{transform}
{

}

void MarchingSquaresPhysics::MSPhysicsBuilder::SetDynamic(bool isDynamic) {this->isDynamic = isDynamic;}

void MarchingSquaresPhysics::MSPhysicsBuilder::Build()
{
    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.position = object->transform->GetPositionb2();
    bodyDef.rotation = object->transform->GetRotationb2();

    bodyDef.type = isDynamic ? b2_dynamicBody : b2_staticBody;
    object->bodyId = b2CreateBody(PhysicsWorld::GetWorldId(),&bodyDef);

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

        object->shapes.push_back(b2CreatePolygonShape(object->bodyId,&shapeDef,&polygon));
    }
}

MarchingSquaresPhysics::MSPhysicsBuilder::MSPhysicsBuilder(MarchingSquaresPhysics* object):object(object),isDynamic(false) {}
MarchingSquaresPhysics::MSPhysicsBuilder MarchingSquaresPhysics::GetBuilder() {return {this};}

void MarchingSquaresPhysics::Update()
{
    b2Vec2 position = b2Body_GetPosition(bodyId);
    b2Rot rotation = b2Body_GetRotation(bodyId);

    transform->SetPosition(position);
    transform->SetRotation(rotation);
}
