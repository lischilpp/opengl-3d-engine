#include <vector>
#include <chrono>
#include <thread>
#include "components/EngineComponent.h"
#include "components/System/Time.h"

class LSE
{
public:
    LSE(System::Time* time);
    ~LSE();
    unsigned int AddComponent(EngineComponent* comp);
    EngineComponent* GetComponent(int compID);
    void Update();
    void UpdateLoop();
    void Render();
private:
    std::vector<EngineComponent*> components;
    System::Time* time;
    float fixedUpdate_lastTime,
          fixedUpdate_interval;
};
