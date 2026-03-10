#include "MarchingSquaresPhysicsDecimate.h"

#include <iostream>
#include <Physics/PhysicsWorld.h>

MarchingSquaresPhysicsDecimate::MarchingSquaresPhysicsDecimate(Transform* transform):transform(transform) {}
MarchingSquaresPhysicsDecimate::~MarchingSquaresPhysicsDecimate()
{
    if(b2Body_IsValid(bodyId))
    {
        b2DestroyBody(bodyId);
    }
}



void MarchingSquaresPhysicsDecimate::MSPhysicsBuilder::SetDynamic(bool isDynamic) {this->isDynamic=isDynamic;}
void MarchingSquaresPhysicsDecimate::MSPhysicsBuilder::AddLine(Line line, int x, int y, int lineNo)
{
    int lineIndex = getIndex(x,y,lineNo);
    lineArray[lineIndex] = line;
    lineCount++;
}

void MarchingSquaresPhysicsDecimate::MSPhysicsBuilder::Build()
{
    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.position = object->transform->GetPositionb2();
    bodyDef.rotation = object->transform->GetRotationb2();

    bodyDef.type = isDynamic ? b2_dynamicBody : b2_staticBody;
    object->bodyId = b2CreateBody(PhysicsWorld::GetWorldId(),&bodyDef);

    b2ShapeDef shapeDef = b2DefaultShapeDef();
    Line defaultLine = {};
    int count{};
}

MarchingSquaresPhysicsDecimate::MSPhysicsBuilder::MSPhysicsBuilder(MarchingSquaresPhysicsDecimate* object, int gridWidth, int gridHeight)
    :object(object),gridWidth(gridWidth),gridHeight(gridHeight),isDynamic(false),lineCount(0)
{
    //2 lines per cell
    lineArray = new Line[gridWidth * gridHeight * 2];
}

MarchingSquaresPhysicsDecimate::MSPhysicsBuilder MarchingSquaresPhysicsDecimate::GetBuilder(int gridWidth, int gridHeight)
{
    return {this,gridWidth,gridHeight};
}
