#pragma once

#include <box2d/box2d.h>

class PhysicsWorld
{
    friend class WorldBuilder;
public:
    class WorldBuilder
    {
        friend class PhysicsWorld;
    public:
        WorldBuilder* SetGravity(const b2Vec2 gravity){worldDef.gravity = gravity;return this;}

        void Build() const {PhysicsWorld::worldId = b2CreateWorld(&worldDef);}
    protected:
        WorldBuilder();
        b2WorldDef worldDef;
    };

    static WorldBuilder CreateWorldBuilder();
protected:
    static b2WorldId worldId;
};