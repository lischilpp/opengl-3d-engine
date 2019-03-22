#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Types/RGB.h"
#include "../EngineComponent.h"

namespace System {
class Window: public EngineComponent
{
public:
    GLFWwindow* context;
    float width, height;
    const char* title;
    RGB background;

    void SetSize(float width, float height);
    void SetTitle(const char* title);
    void SetBackground(float r, float g, float b);
    bool Running();
    bool Open();
    void Close();
    void Clear();
    void SetVSync(bool enable);
    ~Window();
};
}
