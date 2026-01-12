#pragma once

#include <SFML/Graphics.hpp>
#include "InputHandler.h"
#include "../Physics/PhysicsWorld.h"
#include "../Rendering/Camera.h"

class BaseApplication
{
public:
    BaseApplication();
    virtual ~BaseApplication();

    void Gameloop();
protected:
    virtual void PollEvents();
    virtual void Input() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;

    //Systems
    sf::RenderWindow window;
    InputHandler input;
    PhysicsWorld physics;

    sf::Color clearColour;

    Camera camera;
};
