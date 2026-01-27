#pragma once
#include<box2d/box2d.h>
#include <GameObjects/GameObject.h>
#include <Rendering/ColourBoxRenderable.h>

class StaticPhysicsFloor: public GameObject
{
public:
    StaticPhysicsFloor();

    void Init() override;

    void Update() override;

    void Render(sf::RenderWindow* window) override;

private:
    ColourBoxRenderable renderable;
    b2BodyId bodyId;
};
