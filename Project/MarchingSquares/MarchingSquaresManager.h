#pragma once

#include <GameObjects/Transform.h>
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

    void Add(float* data, int width, int height, bool dynamic, Transform& transform);
    void Add(VoxelGrid* data, bool dynamic, Transform& transform);

    void TakeInput(InputHandler* inputHandler);
    void Update();
    void Render(sf::RenderWindow* window);
private:
    std::vector<MarchingSquaresObject*> MSObjects;
    std::vector<MSDrawableObject*> MSDrawables;

    bool mouseLeftPressed;
    bool mouseRightPressed;
};
