#include "../headers/Random.h"

float Random::getFloat()
{
    return ((float) rand()) / (float) RAND_MAX;
}

int Random::getInt() {
    return round(getFloat());
}

glm::vec3 Random::getColor()
{
    return glm::vec3(getFloat(), getFloat(), getFloat());
}
