#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:
    GLFWwindow* context;
    float width, height;
    const char* title;
    bool running();
    Window(float width, float height, const char* title);
    ~Window();
private:
    int create();
};

