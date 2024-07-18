#pragma once
#include <math.h>

class Math
{
public:
    static constexpr float PI = M_PI;
    static float Clamp(float n, float s, float e);
};
