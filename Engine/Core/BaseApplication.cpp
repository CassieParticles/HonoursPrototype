#include "BaseApplication.h"

#include "Timer.h"

BaseApplication::BaseApplication():window{sf::VideoMode({800,800}),"SFML Window"},input(&window)
{
    clearColour = sf::Color::Cyan;

    camera.Zoom(1.0f);

    tempShape.setFillColor(sf::Color::Red);
    tempShape.setSize({1,1});
    tempShape.setPosition({0,0});

    Timer::Init();
}

BaseApplication::~BaseApplication()
{

}

void BaseApplication::Gameloop()
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

void BaseApplication::PollEvents()
{
    input.PollEvents();
}


void BaseApplication::Input()
{

}


void BaseApplication::Update() {}


void BaseApplication::Render()
{
    window.clear(clearColour);
    window.setView(camera.getView());

    //Rendering stuff

    window.draw(tempShape);



    window.display();
}
