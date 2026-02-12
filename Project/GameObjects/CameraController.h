#pragma once
#include <GameObjects/GameObject.h>


class Camera;

class CameraController:public GameObject
{
public:
    CameraController(Camera* camera);

    void SetMoveSpeed(float newSpeed);

    void TakeInput(InputHandler* input) override;

    void Update() override;
private:
    Camera* camera;
    float moveSpeed;

    sf::Vector2f translation;
    float scale;
};
