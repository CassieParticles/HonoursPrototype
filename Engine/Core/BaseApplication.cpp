#include "BaseApplication.h"

#include "Timer.h"

BaseApplication::BaseApplication():window{sf::VideoMode({800,800}),"SFML Window"},input(&window)
{
    clearColour = sf::Color::Cyan;

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

        //Pre-update
        PhysicsWorld::UpdateWorld();

        Update();

        //Pre-render
        window.clear(clearColour);
        window.setView(camera.getView());

        Render();

        //Post-render
        window.display();
    }
}

void BaseApplication::PollEvents()
{
    input.PollEvents();
}
