#include "LineGroup.h"

#include <iostream>
LineGroup::LineGroup() {}
LineGroup::~LineGroup() {}

void LineGroup::DouglasPeucker(float tolerance)
{
    std::list<sf::Vector2f> newList;

    auto start = vertices.begin();
    auto end = --vertices.end();
    auto pen = std::prev(end);

    //Add first, penultimate and last vertices
    newList.push_back(*start);    //First
    newList.push_back(*pen);     //Penultimate
    newList.push_back(*end);     //End



    auto startN = newList.begin();
    auto endN = --newList.end();
    auto penN = std::prev(endN);

    //Run douglas Peucker on line
    DP(start,pen,startN,penN,tolerance, newList);
    //Don't need to run between pen & end cause there are no vertices between them

    //Debug info
    std::cout<<"Old vertex count, "<<vertices.size()<<std::endl;
    std::cout<<"New vertex count, "<<newList.size()<<std::endl;

    //Set the vertices to the new list
    vertices = newList;
}

void LineGroup::DP(const std::list<sf::Vector2f>::iterator& start, const std::list<sf::Vector2f>::iterator& end,
                   const std::list<sf::Vector2f>::iterator& nStart, const std::list<sf::Vector2f>::iterator& nEnd, float tolerance, std::
                   list<sf::Vector2f>& newList)
{
    if(std::next(start) == end){return;}

    float maxDistance{};
    std::list<sf::Vector2f>::iterator currentFurthest = std::next(start);

    //Get the furthest vertex
    for(auto it = start;it!=end;++it)
    {
        float dist = perpDist(*start,*end,*it);
        if(dist > maxDistance)
        {
            currentFurthest = it;
            maxDistance = dist;
        }
    }
    //Exit if furthest is within tolerance
    if(maxDistance < tolerance){return;}

    auto newVal = newList.insert(nEnd,*currentFurthest);

    //Run recursively on
    DP(start,currentFurthest,nStart,newVal,tolerance,newList);
    DP(currentFurthest,end,newVal,nEnd,tolerance,newList);
}

float LineGroup::perpDist(sf::Vector2f A, sf::Vector2f B, sf::Vector2f P)
{
    //Get distance between A and B sqr
    float lineLenSqr = (B-A).lengthSquared();

    float mu = ((P.x - A.x) * (B.x - A.x) + (P.y - A.y) * (B.y - A.y)) / lineLenSqr;
    sf::Vector2f closestPoint = A + (B-A) * mu;

    return (closestPoint - P).length();
}
