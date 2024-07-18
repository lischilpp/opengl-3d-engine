#include <iostream>

#include "LS3D/LSE.h"
#include "LS3D/components/EngineComponent.h"

LSE::LSE(System::Time* time)
{
    this->time = time;
    this->fixedUpdate_lastTime = 0.0f;
    this->fixedUpdate_interval = 0.001f;
}

unsigned int LSE::AddComponent(EngineComponent* comp)
{
    components.push_back(comp);
    return components.size() - 1;
}

EngineComponent* LSE::GetComponent(int compID)
{
    return components[compID];
}

void LSE::Update()
{
    for (unsigned int i = 0; i < components.size(); i++)
    {
        components[i]->Update();
    }

    if (time->time - fixedUpdate_lastTime > fixedUpdate_interval)
    {
        for (unsigned int i = 0; i < components.size(); i++)
        {
            components[i]->FixedUpdate();
        }
        fixedUpdate_lastTime = time->time;
    }
}

void LSE::UpdateLoop()
{
    Update();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    UpdateLoop();
}

LSE::~LSE()
{

}
