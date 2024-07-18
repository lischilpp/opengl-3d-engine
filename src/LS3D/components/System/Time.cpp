#include "LS3D/components/System/Time.h"

System::Time::Time()
{
    this->lastTime = glfwGetTime();
    this->Update();
}

void System::Time::Update()
{
    this->time = glfwGetTime();
    this->deltaTime = this->time - this->lastTime;
    this->lastTime = time;
}

float System::Time::Get()
{
    return glfwGetTime();
}
