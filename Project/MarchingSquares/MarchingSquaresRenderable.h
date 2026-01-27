#pragma once
#include <Rendering/BaseRenderable.h>

#include "Triangle.h"

class MarchingSquaresRenderable:BaseRenderable
{
public:
    MarchingSquaresRenderable(Transform* transform);
    void Render(sf::RenderWindow* RenderWindow) override;


    class MSRenderableBuilder
    {
        friend class MarchingSquaresRenderable;
    public:
        void AddTriangle(Triangle triangle);
        void Build();
    private:
        std::vector<Triangle> triangles;
        MarchingSquaresRenderable* renderable;
        MSRenderableBuilder(MarchingSquaresRenderable* renderable);
    };
    MSRenderableBuilder GetBuilder();

    sf::RenderStates renderState;
private:
    sf::VertexArray triangles;
};
