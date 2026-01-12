#pragma once
#include "BaseRenderable.h"

class ColourBoxRenderable:public BaseRenderable
{
public:
    ColourBoxRenderable(Transform* transform, const sf::Color& colour);


    void Render(sf::RenderWindow* RenderWindow) override;

    sf::RectangleShape shape;
    sf::Color colour;
};
