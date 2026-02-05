#include "MSObject.h"

#include "Generators/MSBasicGenerator.h"

MSObject::MSObject():physics(&transform),renderer(&transform)
{
}

void MSObject::SetData(float* data, int width, int height)
{
    grid = VoxelGrid(data, width, height);

    grid.AddBorder(-1);

    generator = new MSBasicGenerator(&grid);
}

void MSObject::Generate()
{
    MSTrianglePhysics::MSTrianglePhysicsBuilder physicsBuilder = physics.GetBuilder();
    MSTriangleRenderer::MSTriangleRendererBuilder rendererBuilder = renderer.GetBuilder();

    physicsBuilder.SetDynamic(false);

    generator->AddBuilder(&physicsBuilder);
    generator->AddBuilder(&rendererBuilder);

    generator->Generate();
}

void MSObject::Update()
{
    physics.Update();
}

void MSObject::Render(sf::RenderWindow* window)
{
    renderer.Render(window);
}
