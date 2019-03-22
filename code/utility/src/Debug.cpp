#include "../headers/Debug.h"

void Debug::log(string msg)
{
    std::cout << msg << std::endl;
}

void Debug::log(int x)
{
    std::cout << x << std::endl;
}

void Debug::log(glm::vec3 v)
{
    std::cout << "x=" << v.x << " y=" << v.y << " z=" << v.z << std::endl;
}
