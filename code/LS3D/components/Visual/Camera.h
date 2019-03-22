#pragma once
#include "../EngineComponent.h"
#include "../System/Window.h"
#include "../Types/Vector2.h"
#include "../Types/Vector3.h"
#include "Shader.h"
#include "SceneObject.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Visual
{
class Camera: public EngineComponent
{
public:
    glm::vec3 position;
    float pitch, yaw, roll;
    Camera(System::Window* window);
    void Update();
    void Render();
    void SetFoV(float fov);
    void SetClip(float near_clip, float far_clip);
    void SetPositionX(float x);
    void SetPositionY(float y);
    void SetPositionZ(float z);
    void SetPosition(float x, float y, float z);
    void TranslateX(float a);
    void TranslateY(float a);
    void TranslateZ(float a);
    void Translate(float x, float y, float z);
    void SetRotationX(float x);
    void SetRotationY(float y);
    void SetRotationZ(float z);
    void SetRotation2(float x, float y);
    void SetRotation(float x, float y, float z);
    void SetPitch(float pitch);
    void SetYaw(float yaw);
    void SetRoll(float roll);
    void RotateX(float x);
    void RotateY(float y);
    void RotateZ(float z);
    void Rotate(float x, float y, float z);
    void Rotate2(float x, float y);
    Vector2 GetRotation2();
private:
    System::Window* window;
    glm::vec3 up, front;
    glm::mat4 model, view, projection;
    float fov, near_clip, far_clip;
};
}
