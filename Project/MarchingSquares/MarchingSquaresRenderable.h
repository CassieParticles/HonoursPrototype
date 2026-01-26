#pragma once
#include <Rendering/BaseRenderable.h>

struct Triangle
{
    Triangle(const sf::Vector2f& a = {}, const sf::Vector2f& b = {}, const sf::Vector2f& c = {})
        : A(a),
          B(b),
          C(c) {}

    sf::Vector2f A;
    sf::Vector2f B;
    sf::Vector2f C;
};

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
