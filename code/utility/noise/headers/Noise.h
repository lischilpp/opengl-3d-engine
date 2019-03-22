#include "../../../ext/noise/headers/simplexnoise.h"

class Noise
{
public:
    static int get(float x, float y, float z);
    static int get2(int x, int z, float scale, float amp);
    static int get3(int x, int y, int z, float scale, float amp);
    static int getOctave2(int x, int z, int octaves, float scale, float scaleFactor, float amp, float ampFactor);
};
