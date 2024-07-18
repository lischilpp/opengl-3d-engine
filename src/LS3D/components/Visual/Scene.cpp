#include "LS3D/components/Visual/Scene.h"

namespace Visual {

void Scene::Update()
{
    for (unsigned int i = 0; i < Objects.size(); i++)
    {
        Objects[i]->Update();
    }
}

void Scene::Render()
{
    for (unsigned int i = 0; i < Objects.size(); i++)
    {
        Objects[i]->Render();
    }
}

void Scene::AddObject(SceneObject* obj)
{
    Objects.push_back(obj);
}

SceneObject* Scene::GetObject(int i)
{
    return Objects[i];
}

void Scene::AddShader(Shader* shader)
{
    Shaders.push_back(shader);
}

Shader* Visual::Scene::GetShader(int i)
{
    return Shaders[i];
}

void Scene::SetWireframeMode(bool enable)
{
    if (enable)
        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    else
        glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
}

void Scene::SetBackfaceCulling(bool enable)
{
    if (enable)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE);
}

}
