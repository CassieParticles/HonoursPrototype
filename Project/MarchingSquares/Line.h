#pragma once
#include <SFML/System/Vector2.hpp>


struct Line
{
    Line(sf::Vector2f A = {}, sf::Vector2f B = {}):A(A),B(B) {}

    friend bool operator==(const Line& lhs, const Line& rhs)
    {
        return lhs.A == rhs.A && lhs.B == rhs.B;
    }
    friend bool operator!=(const Line& lhs, const Line& rhs) { return !(lhs == rhs); }

    sf::Vector2f A;
    sf::Vector2f B;
};