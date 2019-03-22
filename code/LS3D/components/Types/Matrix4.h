#pragma once
#include <cstring>
#include <GL/glew.h>

class Matrix4
{
public:
    float& operator[](int i);
    static float identity[16];
    Matrix4();
    Matrix4(float data[16]);
private:
    float data[16];
};

