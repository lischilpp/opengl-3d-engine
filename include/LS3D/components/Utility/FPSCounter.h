#include "../EngineComponent.h"
#include "../System/Time.h"
#include <deque>

namespace Utility {
class FPSCounter: public EngineComponent
{
public:
    FPSCounter(System::Time* time);
    void Update();
    void SetPrecision(int precision);
    void SetUpdateInterval(int interval);
    bool Updated();
    float GetAverage();
    float Get();
private:
    System::Time* time;
    std::deque<float> lastFPS;
    int precision, updateInterval;
    float fps, lastUpdate;
    bool updated;
};
}
