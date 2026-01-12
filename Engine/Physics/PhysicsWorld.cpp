#include "PhysicsWorld.h"

b2WorldId PhysicsWorld::worldId;

PhysicsWorld::WorldBuilder::WorldBuilder()
{
    worldDef = b2DefaultWorldDef();
}

PhysicsWorld::WorldBuilder PhysicsWorld::CreateWorldBuilder()
{
    return {};
}
