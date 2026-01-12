#include "Application.h"
Application::Application()
{
    physics.CreateWorldBuilder().SetGravity(b2Vec2(0,-10.0f))->Build();
}
Application::~Application() {}

void Application::Input()
{

}

void Application::Update()
{

}

void Application::Render()
{
    testObject.Render(&window);
}
