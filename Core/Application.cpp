#include "Application.h"

#include <iostream>

Application::Application():window{sf::VideoMode({800,800}),"SFML Window"},input(&window)
{
    clearColour = sf::Color::Cyan;

    camera.Zoom(1.0f);

    tempShape.setFillColor(sf::Color::Red);
    tempShape.setSize({1,1});
    tempShape.setPosition({0,0});

    Timer::Init();
}

Application::~Application()
{

}

void Application::Gameloop()
{
    while(window.isOpen())
    {
        Timer::Update();

        PollEvents();
        Input();
        Update();
        Render();
    }
}

void Application::PollEvents()
{
    input.PollEvents();
}


void Application::Input()
{

}


void Application::Update() {}


void Application::Render()
{
    window.clear(clearColour);
    window.setView(camera.getView());

    //Rendering stuff

    window.draw(tempShape);



    window.display();
}
