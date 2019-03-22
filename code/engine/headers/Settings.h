#include <GLM/glm.hpp>

class Settings
{
public:
    const static int log_chunkSize = 6;
    const static int chunkSize = 1 << Settings::log_chunkSize;
    const static int chunkSurface = Settings::chunkSize * Settings::chunkSize;
    const static int chunkVolume = Settings::chunkSurface * Settings::chunkSize;
    const static int half_chunkSize;
    const static int renderDistance = 4;
    constexpr static float uvUnit = 0.1f;
    static bool useThreading;
};
