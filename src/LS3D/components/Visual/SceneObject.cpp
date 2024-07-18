#include "LS3D/components/Visual/SceneObject.h"

namespace Visual {

Visual::Shader SceneObject::defaultShader;
bool SceneObject::defaultShaderLoaded;

void SceneObject::Render()
{
    if (texture->loaded)
        texture->Use();
    if (!defaultShaderLoaded)
    {
        defaultShader.Load("SceneObject.vert",
                           "SceneObject.frag");
        defaultShaderLoaded = true;
    }
    for (unsigned int i = 0; i < shaders.size(); i++)
        shaders[i]->Use();
    rotationMatrix = glm::mat4_cast(rotation);
    SceneObject::defaultShader.Use();
    GLuint transformLoc = defaultShader.GetUniformLocation("transform");
    GLuint rotationLoc = defaultShader.GetUniformLocation("rotation");
    glUniformMatrix4fv(rotationLoc,  1, GL_FALSE, &rotationMatrix[0][0]);
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, &transform[0]);
    mesh.Render();
}

void SceneObject::Update() {}

void SceneObject::SetPositionX(float x)
{
    transform[12] = x;
}

void SceneObject::SetPositionY(float y)
{
    transform[13] = y;
}

void SceneObject::SetPositionZ(float z)
{
    transform[14] = z;
}

void SceneObject::SetPosition(float x, float y, float z)
{
    transform[12] = x;
    transform[13] = y;
    transform[14] = z;
}

void SceneObject::SetPosition(Vector3 position)
{
    transform[12] = position.x;
    transform[13] = position.y;
    transform[14] = position.z;
}

void SceneObject::TranslateX(float x)
{
    transform[12] += x;
}

void SceneObject::TranslateY(float y)
{
    transform[13] += y;
}

void SceneObject::TranslateZ(float z)
{
    transform[14] += z;
}

void SceneObject::Translate(float x, float y, float z)
{
    transform[12] += x;
    transform[13] += y;
    transform[14] += z;
}

void SceneObject::SetScaleX(float s)
{
    transform[0] = s;
}

void SceneObject::SetScaleY(float s)
{
    transform[5] = s;
}

void SceneObject::SetScaleZ(float s)
{
    transform[10] = s;
}

void SceneObject::SetScale(float s)
{
    transform[0]  = s;
    transform[5]  = s;
    transform[10] = s;
}

void SceneObject::ScaleX(float s)
{
    transform[0] *= s;
}

void SceneObject::ScaleY(float s)
{
    transform[5] *= s;
}

void SceneObject::ScaleZ(float s)
{
    transform[10] *= s;
}

void SceneObject::Scale(float s)
{
    transform[0]  *= s;
    transform[5]  *= s;
    transform[10] *= s;
}

void SceneObject::SetRotationX(float r)
{
    glm::vec3 v = glm::eulerAngles(rotation);
    SetRotation(r, v.y, v.z);
}

void SceneObject::SetRotationY(float r)
{
    glm::vec3 v = glm::eulerAngles(rotation);
    SetRotation(v.x, r, v.z);
}

void SceneObject::SetRotationZ(float r)
{
    glm::vec3 v = glm::eulerAngles(rotation);
    SetRotation(v.x, v.y, r);
}

void SceneObject::SetRotation(float x, float y, float z)
{
    rotation = glm::quat(glm::vec3(x, y, z));
}

void SceneObject::RotateX(float r)
{
    rotation *= glm::angleAxis(r, glm::vec3(1.0f, 0.0f, 0.0f));
}

void SceneObject::RotateY(float r)
{
    rotation *= glm::angleAxis(r, glm::vec3(0.0f, 1.0f, 0.0f));
}

void SceneObject::RotateZ(float r)
{
    rotation *= glm::angleAxis(r, glm::vec3(0.0f, 0.0f, 1.0f));
}

void SceneObject::Rotate(float x, float y, float z)
{
    RotateX(x);
    RotateY(y);
    RotateZ(z);
}

void SceneObject::AddShader(Visual::Shader* shader)
{
    shaders.push_back(shader);
}

void SceneObject::SetTexture(Visual::Texture* texture)
{
    this->texture = texture;
}
}
