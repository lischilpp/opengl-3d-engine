#include "../EngineComponent.h"
#include <vector>
#include "SceneObject.h"

namespace Visual
{
class Scene: public EngineComponent
{
public:
    void AddObject(SceneObject* obj);
    SceneObject* GetObject(int id);

    void AddShader(Shader* shader);
    Shader* GetShader(int id);

    void Update();
    void Render();
    void SetWireframeMode(bool enable);
    void SetBackfaceCulling(bool enable);
private:
    std::vector<SceneObject*> Objects;
    std::vector<Shader*> Shaders;
};
}
