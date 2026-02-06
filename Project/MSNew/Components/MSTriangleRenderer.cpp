#include "MSTriangleRenderer.h"

MSTriangleRenderer::MSTriangleRenderer(Transform* transform):BaseRenderable(transform)
{
    triangles.setPrimitiveType(sf::PrimitiveType::Triangles);

    renderState = sf::RenderStates();
}

void MSTriangleRenderer::Render(sf::RenderWindow* RenderWindow)
{
    renderState.transform = sf::Transform();
    renderState.transform.translate(transform->GetPositionSf());
    renderState.transform.scale(transform->GetScaleSf());
    renderState.transform.rotate(transform->GetRotationSf());

    RenderWindow->draw(triangles,renderState);
}

void MSTriangleRenderer::MSTriangleRendererBuilder::Build()
{
    //Set the size of the vertex array
    renderable->triangles.clear();
    renderable->triangles.resize(triangles.size() * 3);

    for(int i=0;i<triangles.size();++i)
    {
        renderable->triangles[i * 3 + 0].position = triangles[i].A;
        renderable->triangles[i * 3 + 1].position = triangles[i].B;
        renderable->triangles[i * 3 + 2].position = triangles[i].C;
    }
}
MSTriangleRenderer::MSTriangleRendererBuilder::MSTriangleRendererBuilder(MSTriangleRenderer* renderer):renderable{renderer} {}
