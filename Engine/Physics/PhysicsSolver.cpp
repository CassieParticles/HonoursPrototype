#include "PhysicsWorld.h"
PhysicsWorld::WorldBuilder::WorldBuilder(PhysicsWorld* solver):physicsSolver(solver)
{
    worldDef = b2DefaultWorldDef();
}

PhysicsWorld::WorldBuilder PhysicsWorld::CreateWorldBuilder()
{
    return WorldBuilder(this);
}
