#include "../headers/Player.h"

Player::Player(FirstPersonController* controller) {
    this->controller = controller;
}

void Player::update() {
    this->controller->update();
}
