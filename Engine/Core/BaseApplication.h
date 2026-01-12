#pragma once

#include <SFML/Graphics.hpp>
#include "InputHandler.h"
#include "../Rendering/Camera.h"

class BaseApplication
{
public:
    BaseApplication();
    virtual ~BaseApplication();

    void Gameloop();
private:
    virtual void PollEvents();
    virtual void Input();
    virtual void Update();
    virtual void Render();

    //Systems
    sf::RenderWindow window;
    InputHandler input;

    sf::Color clearColour;

    Camera camera;
};
