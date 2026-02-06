#pragma once
#include <GameObjects/GameObject.h>
#include <Rendering/ColourBoxRenderable.h>


class DynamicPhysicsBox: public GameObject
{
public:
    DynamicPhysicsBox();

    void Init() override;

    void Update() override;

    void Render(sf::RenderWindow* window) override;

private:
    ColourBoxRenderable renderable;
    b2BodyId bodyId;
};
