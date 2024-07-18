#include "LS3D/components/Visual/Skybox.h"

namespace Visual
{
Skybox::Skybox(Camera* camera, Texture* texture, GeometryCreator* geometryCreator, float size)
{
    this->camera  = camera;
    this->texture = texture;

    SetTexture(texture);
    geometryCreator->CubeInverted(&mesh, size);
    Cubemap cubemap;
    cubemap.MapToCube(&mesh);
    mesh.Push();
}

void Skybox::Update()
{
    SetPosition(camera->position.x, camera->position.y, camera->position.z);
}
}

