#include <glm/glm.hpp>
#include <random>

class Random
{
public:
    static float getFloat();
    static int getInt();
    static glm::vec3 getColor();
};
