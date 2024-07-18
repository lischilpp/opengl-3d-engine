#include "Debugger.h"

namespace System
{
void Debugger::Log(std::string msg)
{
    std::cout << msg << std::endl;
}

void Debugger::Log(int x)
{
    std::cout << x << std::endl;
}

void Debugger::Log(float x)
{
    std::cout << x << std::endl;
}

void Debugger::Log(double x)
{
    std::cout << x << std::endl;
}


void Debugger::Log(bool b)
{
    std::cout << ((b) ? "true" : "false") << std::endl;
}

void Debugger::Log(Vector2 v)
{
    std::cout << "x=" << v.x << " y=" << v.y << std::endl;
}
}
