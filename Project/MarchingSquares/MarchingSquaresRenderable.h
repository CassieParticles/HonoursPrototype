#pragma once
#include <Rendering/BaseRenderable.h>

#include "TriangleBuilder.h"

class MarchingSquaresRenderable:BaseRenderable
{
public:
    MarchingSquaresRenderable(Transform* transform);

    void Render(sf::RenderWindow* RenderWindow) override;


    class MSRenderableBuilder: public TriangleBuilder
    {
        friend class MarchingSquaresRenderable;
    public:
        void Build() override;
    protected:
        MSRenderableBuilder(MarchingSquaresRenderable* renderable);
        MarchingSquaresRenderable* renderable;
    };
    MSRenderableBuilder GetBuilder();

private:
    sf::RenderStates renderState;
    sf::VertexArray triangles;
};
