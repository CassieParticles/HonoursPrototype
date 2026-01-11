#include "InputHandler.h"
InputHandler::InputHandler(sf::RenderWindow* window):window{window}
{
    keys.resize(sf::Keyboard::KeyCount);
    mouseButtons.resize(sf::Mouse::ButtonCount);
}

InputHandler::~InputHandler()
{

}

void InputHandler::PollEvents()
{
    while(const std::optional event = window->pollEvent())
    {
        //Close the window
        if(event->is<sf::Event::Closed>())
        {
            window->close();
        }
        //Mouse position
        if(event->is<sf::Event::MouseLeft>())
        {
            mousePosition = sf::Vector2i(-1,-1);
            mouseOnScreen = false;
        }
        if(event->is<sf::Event::MouseEntered>())
        {
            mouseOnScreen = true;
        }
        if(mouseOnScreen && event->is<sf::Event::MouseMoved>())
        {
            mousePosition = event->getIf<sf::Event::MouseMoved>()->position;
        }
        //Keyboard pressed/released
        if(event->is<sf::Event::KeyPressed>())
        {
            int code = static_cast<int>(event->getIf<sf::Event::KeyPressed>()->code);
            keys.at(code) = true;
        }
        if(event->is<sf::Event::KeyReleased>())
        {
            int code = static_cast<int>(event->getIf<sf::Event::KeyReleased>()->code);
            keys.at(code) = false;
        }
        //Mouse buttons pressed/released
        if(event->is<sf::Event::MouseButtonPressed>())
        {
            int button = static_cast<int>(event->getIf<sf::Event::MouseButtonPressed>()->button);
            mouseButtons.at(button) = true;
        }
        if(event->is<sf::Event::MouseButtonReleased>())
        {
            int button = static_cast<int>(event->getIf<sf::Event::MouseButtonReleased>()->button);
            mouseButtons.at(button) = false;
        }
    }
}

bool InputHandler::getKey(sf::Keyboard::Key key) {return keys[static_cast<int>(key)];}
bool InputHandler::getMouseButton(sf::Mouse::Button button) {return mouseButtons[static_cast<int>(button)];}
