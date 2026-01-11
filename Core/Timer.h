#pragma once

#include "SFML/System.hpp"


class Timer
{
public:
    static void Init();
    static void Update();

    static float getDeltaTime();
private:
    static sf::Clock clock;

    static sf::Time lastUpdateTime;
    static float deltaTime;
};
