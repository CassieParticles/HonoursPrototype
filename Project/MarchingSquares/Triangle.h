#pragma once
#include <SFML/System/Vector2.hpp>

struct Triangle
{
    Triangle(const sf::Vector2f& a = {}, const sf::Vector2f& b = {}, const sf::Vector2f& c = {})
        : A(a),
          B(b),
          C(c) {}

    sf::Vector2f A;
    sf::Vector2f B;
    sf::Vector2f C;
};
