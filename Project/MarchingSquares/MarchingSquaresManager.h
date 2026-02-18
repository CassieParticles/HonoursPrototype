#pragma once

#include <SFML/Graphics.hpp>

#include "VoxelGrid.h"

class InputHandler;
class MarchingSquaresObject;
class MSDrawableObject;

class MarchingSquaresManager
{
public:
    MarchingSquaresManager();

    ~MarchingSquaresManager();

    void Add(float* data, int width, int height, bool dynamic);
    void Add(VoxelGrid* data, bool dynamic);

    void TakeInput(InputHandler* inputHandler);
    void Update();
    void Render(sf::RenderWindow* window);
private:
    std::vector<MarchingSquaresObject*> MSObjects;
    std::vector<MSDrawableObject*> MSDrawables;

    bool mousePressed;
};
