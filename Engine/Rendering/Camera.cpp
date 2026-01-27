#include "Camera.h"
Camera::Camera()
{
    view.setCenter({0,0});
    view.zoom(0.03f);
}
void Camera::Move(sf::Vector2f moveDirection)
{
    view.move(moveDirection);
}
void Camera::Zoom(float factor)
{
    view.zoom(factor);
}


