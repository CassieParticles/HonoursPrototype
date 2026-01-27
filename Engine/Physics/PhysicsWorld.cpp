#include "PhysicsWorld.h"

#include "../Core/Timer.h"

b2WorldId PhysicsWorld::worldId;

PhysicsWorld::WorldBuilder::WorldBuilder()
{
    worldDef = b2DefaultWorldDef();
}

PhysicsWorld::WorldBuilder PhysicsWorld::CreateWorldBuilder()
{
    return WorldBuilder();
}

b2WorldId PhysicsWorld::GetWorldId()
{
    return worldId;
}

void PhysicsWorld::UpdateWorld()
{
    float deltaTime = Timer::getDeltaTime();
    b2World_Step(worldId,deltaTime,4);
}
