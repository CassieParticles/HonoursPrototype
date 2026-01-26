#include "Timer.h"

sf::Time Timer::lastUpdateTime = sf::Time::Zero;
sf::Clock Timer::clock;
float Timer::deltaTime = 0.0f;
float Timer::elapsedTime = 0.0f;

void Timer::Init()
{
    clock.start();
    deltaTime = 0.f;
    lastUpdateTime = clock.getElapsedTime();
}

void Timer::Update()
{
    sf::Time currentTime = clock.getElapsedTime();
    deltaTime = (currentTime - lastUpdateTime).asSeconds();

    lastUpdateTime = currentTime;
    elapsedTime += deltaTime;
}

float Timer::getDeltaTime() {return deltaTime;}
float Timer::getElapsedTime() {return elapsedTime;}
