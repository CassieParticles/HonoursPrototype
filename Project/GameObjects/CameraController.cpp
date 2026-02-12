#include "CameraController.h"

#include <Core/InputHandler.h>
#include <Core/Timer.h>
#include <Rendering/Camera.h>

CameraController::CameraController(Camera* camera):GameObject(),camera(camera),moveSpeed(1),scrollSpeed(1),translation(),scale(1) {}
void CameraController::SetMoveSpeed(float newSpeed) {moveSpeed = newSpeed;}
void CameraController::SetScrollSpeed(float newSpeed) {scrollSpeed = newSpeed;}

void CameraController::TakeInput(InputHandler* input)
{
    if(input->getKey(sf::Keyboard::Key::W))
    {
        translation.y--;
    }
    if(input->getKey(sf::Keyboard::Key::S))
    {
        translation.y++;
    }
    if(input->getKey(sf::Keyboard::Key::A))
    {
        translation.x--;
    }
    if(input->getKey(sf::Keyboard::Key::D))
    {
        translation.x++;
    }
    if(input->getKey(sf::Keyboard::Key::Hyphen))
    {
        scale++;
    }
    if(input->getKey(sf::Keyboard::Key::Equal))
    {
        scale--;
    }
}

void CameraController::Update()
{
    if(!camera){return;}
    camera->Move(translation * moveSpeed * Timer::getDeltaTime());
    camera->Zoom(1 + scale * scrollSpeed);

    translation = sf::Vector2f();
    scale = 0;
}
