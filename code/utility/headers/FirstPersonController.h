#include "Camera.h"
#include "Input.h"
#include "Time.h"
#include <iostream>

class FirstPersonController
{
public:
    Camera* camera;
    Input* input;
    Time* time;
    void update();
    void moveLeft(float amount);
    void moveRight(float amount);
    void moveDown(float amount);
    void moveUp(float amount);
    void moveBackwards(float amount);
    void moveForwards(float amount);
    float mouseSensitivity;
    void handleInput();
    FirstPersonController(Camera* camera, Input* input, Time* time);
private:
    void handleKeyboardInput();
    bool fastSpeed;
    float fastSpeedFactor;
};
