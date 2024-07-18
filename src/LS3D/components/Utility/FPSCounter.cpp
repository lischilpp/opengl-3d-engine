#include "LS3D/components/Utility/FPSCounter.h"

namespace Utility
{
FPSCounter::FPSCounter(System::Time* time)
{
    this->time = time;
    this->precision = 100;
    this->updateInterval = 1.0f;
    this->lastUpdate = 0.0f;
    this->fps = 0.0f;
    this->updated = false;
}

void FPSCounter::Update()
{
    updated = false;
    lastFPS.push_back(1 / time->deltaTime);

    if ((int)lastFPS.size() > precision)
    {
        lastFPS.pop_front();
    }

    if (time->time - lastUpdate > updateInterval) {
        float total = 0;
        for (unsigned int i = 0; i < lastFPS.size(); i++)
            total += lastFPS[i];
        fps = total / (float)lastFPS.size();
        lastUpdate = time->time;
        updated = true;
    }
}

void FPSCounter::SetPrecision(int precision)
{
    this->precision = precision;
}

void FPSCounter::SetUpdateInterval(int interval)
{
    this->updateInterval = interval;
}

bool FPSCounter::Updated()
{
    return updated;
}

float FPSCounter::GetAverage()
{
    return fps;
}

float FPSCounter::Get()
{
    return 1 / time->deltaTime;
}

}
