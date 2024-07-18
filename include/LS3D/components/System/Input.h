#pragma once
#include <functional>
#include <cstring>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Window.h"
#include "../Types/Vector2.h"
#include "../EngineComponent.h"
#include "../System/Time.h"

namespace System {
class Input: public EngineComponent
{
public:
    static System::Window* window;
    static System::Time time;

    static bool keys[1024],
                keysDown[1024],
                firstMouseMovement,
                mouseMoved,
                mouseButtons[8],
                mouseButtonsDown[8],
                mouseButtonsRelease[8];

    static std::vector<std::function<void()>> keyCallbacks;

    static Vector2 lastMousePosition,
                   mousePosition,
                   mouseMovement;
    static float mousePollingRate, lastMouseUpdate;
    static std::vector<std::function<void(float, float)>> mouseCallbacks;

    Input(System::Window* window);

    // keyboard
    static void key_event(GLFWwindow* window, int key, int scancode, int action, int mode);
    static bool KeyPressed(int key);
    static bool KeyDown(int key);
    static int AddKeyCallback(std::function<void()> callback);
    static void RemoveKeyCallback(int index);

    // mouse
    static void mouse_event(GLFWwindow* window, double x, double y);
    static void mouse_button_event(GLFWwindow* window, int button, int action, int mods);
    static int AddMouseCallback(std::function<void(float, float)> callback);
    static void RemoveMouseCallback(int index);
    void Update();
    void DisableCursor();
    Vector2 GetMouseMovement();
    bool MouseMoved();
};
}
