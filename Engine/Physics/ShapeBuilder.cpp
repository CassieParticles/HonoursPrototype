#include "ShapeBuilder.h"

#include <box2d/box2d.h>

#include "Rigidbody.h"

ShapeBuilder* ShapeBuilder::SetMaterial(b2SurfaceMaterial mat) {shapeDef.material = mat; return this;}
ShapeBuilder* ShapeBuilder::SetContactEvents(bool contactEvents) {shapeDef.enableContactEvents = contactEvents; return this;}
ShapeBuilder* ShapeBuilder::SetHitEvents(bool hitEvents) {shapeDef.enableHitEvents = hitEvents; return this;}

void ShapeBuilder::CreateBoxShape()
{
    sf::Vector2f scale = rigidbody->transform->GetScale();
    b2Polygon box = b2MakeBox(scale.x / 2, scale.y / 2 );
    rigidbody->attachedShapes.push_back(b2CreatePolygonShape(rigidbody->bodyId,&shapeDef,&box));
}


ShapeBuilder::ShapeBuilder(Rigidbody* rigidbody):rigidbody(rigidbody) {shapeDef = b2DefaultShapeDef();}
