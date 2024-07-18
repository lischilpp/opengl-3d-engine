#pragma once
#include <math.h>

class Vector3
{
public:
    Vector3(float x, float y, float z);
    Vector3();
    static float Distance(Vector3 a, Vector3 b);
    float x, y, z;
};

