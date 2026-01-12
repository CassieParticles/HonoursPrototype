#pragma once
#include <Rendering/BaseRenderable.h>


class TestRenderable:public BaseRenderable
{
public:
    TestRenderable(Transform* object);
    void Render(sf::RenderWindow* RenderWindow) override;
protected:
    sf::RectangleShape shape;
};
