#include <GLM/glm.hpp>
#include "../../engine/headers/CubeCreator.h"

class Debug
{
public:
    static void log(string msg);
    static void log(int x);
    static void log(glm::vec3 v);

};
