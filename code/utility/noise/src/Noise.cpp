#include "../headers/Noise.h"
#include <math.h>

int Noise::get(float x, float y, float z)
{
    return Noise::get3(x, y, z, 64.0f, 16.0f);
}

int Noise::get2(int x, int z, float scale, float amp)
{
    return (int)(raw_noise_2d(x/scale, z/scale) * amp);
}

int Noise::get3(int x, int y, int z, float scale, float amp)
{
    return (int)(raw_noise_3d(x/scale, y/scale, z/scale) * amp);
}

int Noise::getOctave2(int x, int z, int octaves, float scale, float scaleFactor, float amp, float ampFactor)
{
    float result = 0.0f;
    for (int i = 0; i < octaves; i++)
    {
        result += Noise::get2(x, z, scale, amp);
        scale *= scaleFactor;
        amp   *= ampFactor;
    }
    return (int)result;
}
