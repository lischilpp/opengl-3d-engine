#include <iostream>
#include <string>
#include "../EngineComponent.h"
#include "../Types/Vector2.h"
#include "../Types/Vector3.h"

namespace System {
class Debugger: public EngineComponent
{
public:
    void Log(std::string msg);
    void Log(int x);
    void Log(float x);
    void Log(double x);
    void Log(bool b);
    void Log(Vector2 v);
    void Log(Vector3 v);
};
}
