#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../EngineComponent.h"

namespace System
{
class Time: public EngineComponent
{
public:
    float time, deltaTime;
    void Update();
    float Get();
    Time();
private:
    float lastTime;
};
}
