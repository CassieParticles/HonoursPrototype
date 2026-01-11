#pragma once
#include <SFML/Graphics.hpp>

class Camera
{
public:
    Camera();

    void Move(sf::Vector2f moveDirection);
    void Zoom(float factor);

    sf::View& getView(){return view;}
private:
    sf::View view;
};
