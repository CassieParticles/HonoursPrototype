#pragma once
#include <list>
#include "../Line.h"

class LineGroup
{
public:
    LineGroup();
    ~LineGroup();

    void AddVertex(sf::Vector2f vertex){vertices.push_back(vertex);}
private:
    std::list<sf::Vector2f> vertices;
};
