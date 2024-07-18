#include "Camera.h"
#include "SceneObject.h"
#include "Cubemap.h"
#include "GeometryCreator.h"

namespace Visual
{
class Skybox: public SceneObject
{
public:
    Skybox(Camera* camera, Texture* texture, GeometryCreator* geometryCreator, float size);
    void Update();
private:
    Camera* camera;
    Texture* texture;
};
}
