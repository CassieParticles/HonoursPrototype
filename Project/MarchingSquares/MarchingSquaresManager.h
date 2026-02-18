#pragma once

#include <SFML/Graphics.hpp>

#include "Object/MarchingSquaresObject.h"

class MarchingSquaresManager
{
public:
    MarchingSquaresManager();

    ~MarchingSquaresManager();

    void Add(float* data, int width, int height, bool dynamic);

    void Update();
    void Render(sf::RenderWindow* window);
private:
    std::vector<MarchingSquaresObject*> MSObjects;
};
