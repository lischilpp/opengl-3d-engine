#include "LS3D/components/System/Input.h"
#include <iostream>

namespace System
{
System::Window* Input::window;
System::Time Input::time;

bool Input::keys[1024],
     Input::keysDown[1024],
     Input::firstMouseMovement,
     Input::mouseMoved,
     Input::mouseButtons[8],
     Input::mouseButtonsDown[8],
     Input::mouseButtonsRelease[8];

Vector2 Input::lastMousePosition,
        Input::mousePosition,
        Input::mouseMovement;

float Input::mousePollingRate = 0.001f,
      Input::lastMouseUpdate  = 0.0f;

std::vector<std::function<void()>> Input::keyCallbacks;
std::vector<std::function<void(float, float)>> Input::mouseCallbacks;

// keyboard
void Input::key_event(GLFWwindow* context, int key, int scancode, int action, int mode)
{
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
        {
            keys[key] = true;
            keysDown[key] = true;
        }
        else if (action == GLFW_RELEASE)
        {
            keys[key] = false;
            keysDown[key] = false;
        }
    }

    for (unsigned int i = 0; i < keyCallbacks.size(); i++)
    {
        keyCallbacks[i]();
    }
}

bool Input::KeyPressed(int i)
{
    return keys[i];
}

bool Input::KeyDown(int i)
{
    return keysDown[i];
}

// mouse
void Input::mouse_event(GLFWwindow* context, double x, double y)
{
    mousePosition.x = x;
    mousePosition.y = y;
    if (firstMouseMovement)
    {
        lastMousePosition = mousePosition;
        firstMouseMovement = false;
    }

    mouseMovement.x = mousePosition.x - lastMousePosition.x;
    mouseMovement.y = mousePosition.y - lastMousePosition.y;

    for (unsigned int i = 0; i < mouseCallbacks.size(); i++)
        mouseCallbacks[i](mousePosition.x, mousePosition.y);

    lastMousePosition = mousePosition;
}

void Input::mouse_button_event(GLFWwindow* window, int button, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        mouseButtons[button] = true;
        mouseButtonsDown[button] = true;
        mouseButtonsRelease[button] = false;
    }
    else if (action == GLFW_RELEASE)
    {
        mouseButtons[button] = false;
        mouseButtonsDown[button] = false;
        mouseButtonsRelease[button] = true;
    }
}


Input::Input(System::Window* window)
{
    this->window = window;

    glfwSetCursorPos(window->context, 0, 0);
    glfwSetInputMode(window->context, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetKeyCallback(window->context, this->key_event);
    glfwSetCursorPosCallback(window->context, this->mouse_event);
    glfwSetMouseButtonCallback(window->context, this->mouse_button_event);
}

void Input::Update()
{
    memset(keysDown, 0, sizeof(keysDown));
    memset(mouseButtonsDown, 0, sizeof(mouseButtonsDown));
    memset(mouseButtonsRelease, 0, sizeof(mouseButtonsRelease));
    mouseMoved = false;
    glfwPollEvents();
}

void Input::DisableCursor()
{
    glfwSetInputMode(window->context, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

bool Input::MouseMoved()
{
    return mouseMoved;
}

Vector2 Input::GetMouseMovement()
{
    return mouseMovement;
}

int Input::AddKeyCallback(std::function<void()> callback)
{
    keyCallbacks.push_back(callback);
    return keyCallbacks.size() - 1;
}

void Input::RemoveKeyCallback(int index)
{
    keyCallbacks.erase(keyCallbacks.begin() + index);
}

int Input::AddMouseCallback(std::function<void(float, float)> callback)
{
    mouseCallbacks.push_back(callback);
    return mouseCallbacks.size() - 1;
}

void Input::RemoveMouseCallback(int index)
{
    mouseCallbacks.erase(mouseCallbacks.begin() + index);
}

}
