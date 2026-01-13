#pragma once
#include <box2d/types.h>

class ShapeBuilder
{
    friend class Rigidbody;
public:
    ShapeBuilder* SetMaterial(b2SurfaceMaterial mat);
    ShapeBuilder* SetContactEvents(bool contactEvents);
    ShapeBuilder* SetHitEvents(bool hitEvents);

    void CreateBoxShape();
protected:
    ShapeBuilder(Rigidbody* rigidbody);
    Rigidbody* rigidbody;
    b2ShapeDef shapeDef;
};
