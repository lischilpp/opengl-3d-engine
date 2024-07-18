#include "LS3D/components/Utility/Math.h"

float Math::Clamp(float n, float s, float e)
{
    if (n < s)
        n = s;
    else if (n > e)
        n = e;
    return n;
}
