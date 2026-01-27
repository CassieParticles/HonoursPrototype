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

Transform* Transform::SetPosition(b2Vec2 position)
{
    return SetPosition(position.x,position.y);
}


Transform* Transform::SetPosition(float x, float y)
{
    return SetPosition(sf::Vector2f(x,y));
}
Transform* Transform::SetRotation(sf::Angle rotation)
{
    this->rotation = rotation;
    transformUpdateFlag = false;
    return this;
}

Transform* Transform::SetRotation(b2Rot rotation)
{
    return SetRotation(b2Rot_GetAngle(rotation));
}

Transform* Transform::SetRotation(float rotation)
{
    return SetRotation(sf::radians(rotation));
}



Transform* Transform::SetScale(sf::Vector2f scale)
{
    this->scale = scale;
    transformUpdateFlag = false;
    return this;
}

Transform* Transform::SetScale(b2Vec2 scale)
{
    return SetScale(scale.x,scale.y);
}

Transform* Transform::SetScale(float x, float y)
{
    return SetScale(sf::Vector2f(x,y));
}


sf::Vector2f Transform::GetPositionSf() {return position;}
sf::Angle Transform::GetRotationSf() {return rotation;}
sf::Vector2f Transform::GetScaleSf() {return scale;}

b2Vec2 Transform::GetPositionb2() {return {position.x,position.y};}
b2Rot Transform::GetRotationb2() {return b2MakeRot(rotation.asRadians());}
b2Vec2 Transform::GetScaleb2() {return {scale.x,scale.y};}

sf::Transform Transform::GetTransformSf()
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
