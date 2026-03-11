#pragma once
#include <list>
#include "../Line.h"

class LineGroup
{
public:
    LineGroup();
    ~LineGroup();

    void AddVertex(sf::Vector2f vertex){vertices.push_back(vertex);}

    void DouglasPeucker(float tolerance);
private:
    //start & end are vertices being iterated through, nStart & nEnd are for adding new vertices, tolerance is tolerance for algorithm
    void DP(const std::list<sf::Vector2f>::iterator& start, const std::list<sf::Vector2f>::iterator& end, const std::list<sf::Vector2f>::
            iterator
            & nStart, const std::list<sf::Vector2f>::iterator& nEnd, float tolerance, std::list<sf::Vector2f>& newList);
    float perpDist(sf::Vector2f A, sf::Vector2f B, sf::Vector2f P);

    std::list<sf::Vector2f> vertices;
};
