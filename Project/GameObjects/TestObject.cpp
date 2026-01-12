#include "TestObject.h"

TestObject::TestObject():colourRenderable(&transform,sf::Color::Yellow)
{
    transform.SetScale(sf::Vector2f(1.0f,1.0f));
}

void TestObject::Render(sf::RenderWindow* window)
{
    colourRenderable.Render(window);
}
