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

        void Build() const {physicsSolver->worldId = b2CreateWorld(&worldDef);}
    protected:
        WorldBuilder(PhysicsWorld* solver);
        PhysicsWorld* physicsSolver;
        b2WorldDef worldDef;
    };

    WorldBuilder CreateWorldBuilder();
protected:
    b2WorldId worldId;
};