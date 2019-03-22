#include "../headers/FirstPersonController.h"

FirstPersonController::FirstPersonController(Camera* camera, Input* input, Time* time) {
    this->camera = camera;
    this->input  = input;
    this->time   = time;

    mouseSensitivity = 0.05f;
    fastSpeedFactor = 2.5f;
    fastSpeed = false;
}

void FirstPersonController::update() {
    handleInput();
    camera->update();
}

void FirstPersonController::handleInput() {
    if (input->getKeyPress(GLFW_KEY_A)) {
        moveLeft(time->deltaTime);
    }
    if (input->getKeyPress(GLFW_KEY_D)) {
        moveRight(time->deltaTime);
    }
    if (input->getKeyPress(GLFW_KEY_LEFT_SHIFT)) {
        moveDown(time->deltaTime);
    }
    if (input->getKeyPress(GLFW_KEY_SPACE)) {
        moveUp(time->deltaTime);
    }
    if (input->getKeyPress(GLFW_KEY_S)) {
        moveBackwards(time->deltaTime);
    }
    if (input->getKeyPress(GLFW_KEY_W)) {
        moveForwards(time->deltaTime);
    }
    if (input->getKeyPress(GLFW_KEY_LEFT_ALT)) {
        if (!fastSpeed) {
            camera->moveSpeed *= fastSpeedFactor;
            fastSpeed = true;
        }
    }else {
        if (fastSpeed) {
            camera->moveSpeed /= fastSpeedFactor;
            fastSpeed = false;
        }
    }
    camera->yaw   += mouseSensitivity * Input::mouseMovement.x;
    camera->pitch -= mouseSensitivity * Input::mouseMovement.y;
    if (camera->pitch > 89.0f)
        camera->pitch = 89.0f;
    else if (camera->pitch < -89.0f)
        camera->pitch = -89.0f;
}

void FirstPersonController::moveLeft(float amount) {
    camera->moveX(camera->moveSpeed * -amount);
}

void FirstPersonController::moveRight(float amount) {
    camera->moveX(camera->moveSpeed * amount);
}

void FirstPersonController::moveDown(float amount) {
    camera->moveY(camera->moveSpeed * -amount);
}

void FirstPersonController::moveUp(float amount) {
    camera->moveY(camera->moveSpeed * amount);
}

void FirstPersonController::moveBackwards(float amount) {
    camera->moveZ(camera->moveSpeed * -amount);
}

void FirstPersonController::moveForwards(float amount) {
    camera->moveZ(camera->moveSpeed * amount);
}

