#include "FPController.h"
#include <iostream>

namespace Interaction
{
FPController::FPController(Visual::Camera* camera, System::Input* input, System::Time* time)
{
    this->camera = camera;
    this->input  = input;
    this->time   = time;
    this->moveSpeed = 10.0f;
    this->mouseSpeed = 0.05f;
    this->firstMouseMovement = true;

    input->AddMouseCallback([this, camera, input] (float mouseX, float mouseY)
    {
        if (firstMouseMovement)
        {
            lastMousePosition.x = mouseX;
            lastMousePosition.y = mouseY;
            firstMouseMovement = false;
        }
        else
        {
            Vector2 rotation = camera->GetRotation2();
            float mouseMovementX = mouseX - lastMousePosition.x;
            float mouseMovementY = mouseY - lastMousePosition.y;
            float newRX = Math::Clamp(rotation.x + mouseMovementY * -mouseSpeed, -89.0f, 89.0f);
            float newRY = rotation.y + mouseMovementX * mouseSpeed;
            camera->SetRotation2(newRX, newRY);
            lastMousePosition.x = mouseX;
            lastMousePosition.y = mouseY;
        }
    });
}

void FPController::FixedUpdate()
{
    if (input->KeyPressed(Keys.Forward))
        camera->TranslateZ(moveSpeed * time->deltaTime);
    if (input->KeyPressed(Keys.Backward))
        camera->TranslateZ(-moveSpeed * time->deltaTime);

    if (input->KeyPressed(Keys.Right))
        camera->TranslateX(moveSpeed * time->deltaTime);
    if (input->KeyPressed(Keys.Left))
        camera->TranslateX(-moveSpeed * time->deltaTime);

    if (input->KeyPressed(Keys.Up))
        camera->TranslateY(moveSpeed * time->deltaTime);
    if (input->KeyPressed(Keys.Down))
        camera->TranslateY(-moveSpeed * time->deltaTime);

}

void FPController::Update()
{
    camera->Update();
}

}
