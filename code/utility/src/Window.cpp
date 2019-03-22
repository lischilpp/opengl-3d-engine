#include "../headers/Window.h"
using namespace std;

Window::Window(float width, float height, const char* title)
{
    this->width  = width;
    this->height = height;
    this->title  = title;
    create();
}

int Window::create()
{
    if (!glfwInit()) // init GLFW
        return -1;

    context = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!context) // abort if window couldn't be created
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(context); // make window current context
    glewInit();

    glViewport(0, 0, width, height);

    glEnable (GL_DEPTH_TEST); // enable depth-testing
    glDepthFunc (GL_LESS); // depth-testing interprets a smaller value as "closer"
    glEnable(GL_CULL_FACE);

    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return 1;
}

bool Window::running()
{
    return !glfwWindowShouldClose(context);
}

Window::~Window()
{
    glfwTerminate();
}
