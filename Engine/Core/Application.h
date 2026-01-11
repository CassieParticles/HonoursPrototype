#pragma once

#include <SFML/Graphics.hpp>
#include "InputHandler.h"
#include "../Rendering/Camera.h"

class Application
{
public:
    Application();
    ~Application();

    void Gameloop();
private:
    void PollEvents();
    void Input();
    void Update();
    void Render();

    //Systems
    sf::RenderWindow window;
    InputHandler input;

    sf::Color clearColour;

    sf::RectangleShape tempShape;
    Camera camera;
};
