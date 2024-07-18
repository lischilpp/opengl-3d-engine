#pragma once
#include <math.h>

class Vector2
{
public:
    static float Distance(Vector2 a, Vector2 b);

    float x, y;
    Vector2();
    Vector2(float x, float y);
};

