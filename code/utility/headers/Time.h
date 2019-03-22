#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Time
{
public:
    float time, deltaTime;
    void update();
    Time();
private:
    float lastTime;
};
