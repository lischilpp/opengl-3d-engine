#include "../headers/Time.h"

Time::Time() {
    this->lastTime = glfwGetTime();
    this->update();
}

void Time::update() {
    this->time = glfwGetTime();
    this->deltaTime = this->time - this->lastTime;
    this->lastTime = time;
}
