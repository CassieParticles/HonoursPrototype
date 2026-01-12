#include "Transform.h"
Transform::Transform(sf::Vector2f position, sf::Angle rotation, sf::Vector2f scale)
{
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;

    transformUpdateFlag = false;
}

Transform* Transform::SetPosition(sf::Vector2f position)
{
    this->position = position;
    transformUpdateFlag = false;
    return this;
}
Transform* Transform::SetPosition(float x, float y)
{
    SetPosition(sf::Vector2f(x,y));
    return this;
}
Transform* Transform::SetRotation(sf::Angle rotation)
{
    this->rotation = rotation;
    transformUpdateFlag = false;
    return this;
}
Transform* Transform::SetRotation(float rotation)
{
    SetRotation(sf::radians(rotation));
    return this;
}
Transform* Transform::SetScale(sf::Vector2f scale)
{
    this->scale = scale;
    transformUpdateFlag = false;
    return this;
}
Transform* Transform::SetScale(float x, float y)
{
    SetScale(sf::Vector2f(x,y));
    return this;
}

sf::Vector2f Transform::GetPosition() {return position;}
sf::Angle Transform::GetRotation() {return rotation;}
sf::Vector2f Transform::GetScale() {return scale;}

sf::Transform Transform::GetTransform()
{
    if(!transformUpdateFlag)
    {
        UpdateTransform();
    }
    return transform;
}

void Transform::UpdateTransform()
{
    transform = sf::Transform();

    transform.rotate(rotation);
    transform.scale(scale);
    transform.translate(position);

    transformUpdateFlag = true;
}
