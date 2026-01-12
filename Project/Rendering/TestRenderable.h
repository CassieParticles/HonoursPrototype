#pragma once
#include <Rendering/Renderable.h>


class TestRenderable:public Renderable
{
public:
    TestRenderable(Transform* object);
    void Render(sf::RenderWindow* RenderWindow) override;
protected:
    sf::RectangleShape shape;
};
