#include "ColourBoxRenderable.h"
ColourBoxRenderable::ColourBoxRenderable(Transform* transform, const sf::Color& colour): BaseRenderable(transform), colour(colour)
{
    shape.setSize(sf::Vector2f(1,1));
}

void ColourBoxRenderable::Render(sf::RenderWindow* RenderWindow)
{
    shape.setPosition(transform->GetPosition());
    shape.setRotation(transform->GetRotation());
    shape.setScale(transform->GetScale());

    shape.setFillColor(colour);

    BaseRenderable::Render(RenderWindow);
}
