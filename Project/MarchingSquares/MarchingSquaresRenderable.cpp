#include "MarchingSquaresRenderable.h"
MarchingSquaresRenderable::MarchingSquaresRenderable(Transform* transform):BaseRenderable(transform)
{
    triangles.setPrimitiveType(sf::PrimitiveType::Triangles);
}

void MarchingSquaresRenderable::Render(sf::RenderWindow* RenderWindow)
{
    RenderWindow->draw(triangles);
}

MarchingSquaresRenderable::MSRenderableBuilder::MSRenderableBuilder(MarchingSquaresRenderable* renderable):renderable(renderable) {}
void MarchingSquaresRenderable::MSRenderableBuilder::AddTriangle(Triangle triangle) {triangles.push_back(triangle);}

void MarchingSquaresRenderable::MSRenderableBuilder::Build()
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


MarchingSquaresRenderable::MSRenderableBuilder MarchingSquaresRenderable::GetBuilder()
{
    return {this};
}

