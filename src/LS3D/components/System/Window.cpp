#include "Window.h"
using namespace std;

namespace System
{
void Window::SetSize(float width, float height)
{
    this->width  = width;
    this->height = height;
}

void Window::SetTitle(const char* title)
{
    this->title  = title;
}

void Window::SetBackground(float r, float g, float b)
{
    this->background.r = r;
    this->background.g = g;
    this->background.b = b;
}

bool Window::Open()
{
    if (!glfwInit()) // init GLFW
        return false;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    context = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!context) // abort if window couldn't be created
    {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(context); // make window current context
    glewExperimental = GL_TRUE;
    glewInit();

    glViewport(0, 0, width, height);

    glEnable (GL_DEPTH_TEST); // enable depth-testing
    glDepthFunc (GL_LESS); // depth-testing interprets a smaller value as "closer"
    glEnable(GL_CULL_FACE);

    return true;
}

bool Window::Running()
{
    glfwSwapBuffers(context);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(background.r, background.g, background.b, 1.0f);

    return !glfwWindowShouldClose(context);
}

void Window::Close()
{
    glfwSetWindowShouldClose(context, true);
}

void Window::SetVSync(bool enable)
{
    glfwSwapInterval((int)enable);
}

Window::~Window()
{
    glfwTerminate();
}
}
