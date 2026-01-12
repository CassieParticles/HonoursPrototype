#include "TestRenderable.h"
TestRenderable::TestRenderable(Transform* object):BaseRenderable(object)
{
    shape.setFillColor(sf::Color::Yellow);
    shape.setSize(sf::Vector2f(1.0f,1.0f));
}

void TestRenderable::Render(sf::RenderWindow* RenderWindow)
{
    shape.setPosition(transform->GetPosition());
    shape.setRotation(transform->GetRotation());
    shape.setScale(transform->GetScale());

    RenderWindow->draw(shape);
}
