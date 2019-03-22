#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
using namespace glm;

class Camera
{
public:
    vec3 position;
    float moveSpeed;
    void update();
    void moveX(float amount);
    void moveY(float amount);
    void moveZ(float amount);
    float yaw, pitch;
    Camera(float window_width, float window_height, GLuint shader_program, vec3 position);
private:
    float window_width, window_height;
    GLuint shader_program;
    vec3 up;
    vec3 front;
    mat4 model;
    mat4 view;
    mat4 projection;
};
