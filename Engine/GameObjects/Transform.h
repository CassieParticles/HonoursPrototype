#pragma once

#include <SFML/Graphics.hpp>

class Transform
{
public:
    Transform(sf::Vector2f position = sf::Vector2f(), sf::Angle rotation=sf::Angle(), sf::Vector2f scale = sf::Vector2f(1,1));

    Transform* SetPosition(sf::Vector2f position);
    Transform* SetPosition(float x, float y);

    Transform* SetRotation(sf::Angle rotation);
    Transform* SetRotation(float rotation);

    Transform* SetScale(sf::Vector2f scale);
    Transform* SetScale(float x, float y);

    sf::Vector2f GetPosition();
    sf::Angle GetRotation();
    sf::Vector2f GetScale();

    sf::Transform GetTransform();
protected:
    void UpdateTransform();
    sf::Transform transform;
    bool transformUpdateFlag;

    sf::Vector2f position;
    sf::Angle rotation;
    sf::Vector2f scale;

};
