#include "PhysicsSolver.h"
PhysicsSolver::WorldBuilder::WorldBuilder(PhysicsSolver* solver):physicsSolver(solver)
{
    worldDef = b2DefaultWorldDef();
}

PhysicsSolver::WorldBuilder PhysicsSolver::CreateWorldBuilder()
{
    return WorldBuilder(this);
}
