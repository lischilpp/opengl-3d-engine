#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>
#include "Window.h"
using namespace std;

class Input
{
public:
    static bool keys[1024];
    static bool keysDown[1024];
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
    static bool getKeyPress(int key);
    static bool getKeyDown(int key);
    static void mouse_callback(GLFWwindow* window, double x, double y);
    static bool firstMouseCallback;
    static glm::vec2 mousePos, lastMousePos, mouseMovement;
    static Window* window;
    void update();
    void lateUpdate();
    Input(Window* window);
};

