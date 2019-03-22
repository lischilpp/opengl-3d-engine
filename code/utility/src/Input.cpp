#include "../headers/Input.h"
#include <iostream>

bool Input::keys[1024];
bool Input::keysDown[1024];
glm::vec2 Input::mousePos;
glm::vec2 Input::lastMousePos;
glm::vec2 Input::mouseMovement;
bool Input::firstMouseCallback = true;
Window* Input::window;

Input::Input(Window* window)
{
    glfwSetInputMode(window->context, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetKeyCallback(window->context, this->key_callback);
    glfwSetCursorPosCallback(window->context, this->mouse_callback);
    glfwSwapInterval(1);
    glfwSetCursorPos(window->context, 0, 0);
    Input::window = window;
}

void Input::key_callback(GLFWwindow* context, int key, int scancode, int action, int mode)
{
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
            {
            Input::keys[key] = true;
        }
        else if (action == GLFW_RELEASE)
        {
            Input::keys[key] = false;
            Input::keysDown[key] = true;
        }
    }
}

void Input::mouse_callback(GLFWwindow* context, double x, double y)
{
    if (x != mousePos.x && y != mousePos.y)
    {
        Input::mousePos.x = x - window->width  * 0.5;
        Input::mousePos.y = y - window->height * 0.5;
        if (firstMouseCallback)
        {
            Input::lastMousePos = mousePos;
            firstMouseCallback = false;
        }

        Input::mouseMovement = Input::mousePos - Input::lastMousePos;
        if (Input::mouseMovement.y == -0.5f)
            Input::mouseMovement.y = 0.0f;
        Input::lastMousePos = mousePos;
    }
}

bool Input::getKeyPress(int i)
{
    return keys[i];
}

bool Input::getKeyDown(int i)
{
    if (Input::keysDown[i])
    {
        Input::keysDown[i] = false;
        return true;
    }
    else
    {
        Input::keysDown[i] = false;
        return false;
    }
}

void Input::update()
{
    glfwPollEvents();
}

void Input::lateUpdate()
{
    mouseMovement.x = 0.0f;
    mouseMovement.y = 0.0f;
}
