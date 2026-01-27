#include "ColourBoxRenderable.h"
ColourBoxRenderable::ColourBoxRenderable(Transform* transform, const sf::Color& colour): BaseRenderable(transform), colour(colour)
{
    shape.setSize(sf::Vector2f(1,1));
    shape.setOrigin(sf::Vector2f(0.5,0.5));
}

void ColourBoxRenderable::Render(sf::RenderWindow* RenderWindow)
{
    shape.setPosition(transform->GetPositionSf());
    shape.setRotation(transform->GetRotationSf());
    shape.setScale(transform->GetScaleSf());

    shape.setFillColor(colour);

    RenderWindow->draw(shape);
}
