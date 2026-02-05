#pragma once
#include <Rendering/BaseRenderable.h>

#include "../MSComponent.h"


class MSTriangleRenderer:public MSComponent, public BaseRenderable
{
public:

    explicit MSTriangleRenderer(Transform* transform);

    void Render(sf::RenderWindow* RenderWindow) override;

    class MSTriangleRendererBuilder: public MSTriangleBuilder
    {
        friend class MSTriangleRenderer;
    public:
        void Build() override;

    protected:
        MSTriangleRendererBuilder(MSTriangleRenderer* renderer);
        MSTriangleRenderer* renderable;
    };
    MSTriangleRendererBuilder GetBuilder(){return {this};}

protected:
    sf::RenderStates renderState;
    sf::VertexArray triangles;
};
