#include "../headers/Math.h"

float Math::vectorDistance(glm::ivec3 a, glm::ivec3 b) {
    return sqrt((b.x - a.x) * (b.x - a.x)+
                (b.y - a.y) * (b.y - a.y)+
                (b.z - a.z) * (b.z - a.z));
}
