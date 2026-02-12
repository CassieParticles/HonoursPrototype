#pragma once

#include <SFML/Graphics.hpp>

class InputHandler
{
public:
    InputHandler(sf::RenderWindow* window);
    ~InputHandler();

    void PollEvents();

    bool getKey(sf::Keyboard::Key key);
    bool getMouseButton(sf::Mouse::Button button);

    sf::Vector2i getMousePosition(){return mousePosition;};

    float getScroll();

private:
    sf::RenderWindow* window;

    sf::Vector2i mousePosition;
    bool mouseOnScreen;

    std::vector<bool> keys;
    std::vector<bool> mouseButtons;

    float scroll;
};