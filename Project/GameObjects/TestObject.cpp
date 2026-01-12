#include "TestObject.h"

#include "../Rendering/TestRenderable.h"

TestObject::TestObject():testRenderable(&transform)
{
    transform.SetScale(sf::Vector2f(1.0f,1.0f));
}

void TestObject::Render(sf::RenderWindow* window)
{
    testRenderable.Render(window);
}
