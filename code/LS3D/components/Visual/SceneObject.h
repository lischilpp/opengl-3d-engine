#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "../Types/Matrix4.h"
#include "../Types/Vector3.h"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Visual
{
class SceneObject
{
public:
    static Visual::Shader defaultShader;
    static bool defaultShaderLoaded;
    Visual::Mesh mesh;
    virtual void Update();
    virtual void Render();
    void SetPositionX(float x);
    void SetPositionY(float y);
    void SetPositionZ(float z);
    void SetPosition(float x, float y, float z);
    void SetPosition(Vector3 position);
    void TranslateX(float x);
    void TranslateY(float y);
    void TranslateZ(float z);
    void Translate(float x, float y, float z);
    void SetScaleX(float s);
    void SetScaleY(float s);
    void SetScaleZ(float s);
    void SetScale(float s);
    void ScaleX(float s);
    void ScaleY(float s);
    void ScaleZ(float s);
    void Scale(float s);
    void SetRotationX(float r);
    void SetRotationY(float r);
    void SetRotationZ(float r);
    void SetRotation(float x, float y, float z);
    void RotateX(float r);
    void RotateY(float r);
    void RotateZ(float r);
    void Rotate(float x, float y, float z);
    void AddShader(Visual::Shader* shader);
    void SetTexture(Visual::Texture* texture);
private:
    Matrix4 transform;
    glm::quat rotation;
    glm::mat4 rotationMatrix;
    std::vector<Visual::Shader*> shaders;
    Visual::Texture* texture;
};
}

