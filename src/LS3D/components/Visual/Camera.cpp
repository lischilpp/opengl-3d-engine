#include "LS3D/components/Visual/Camera.h"

namespace Visual
{
Camera::Camera(System::Window* window)
{
    this->window = window;
    this->pitch = 0.0f;
    this->yaw = 270.0f;
    this->roll = 0.0f;
    this->fov = 45.0f;
    this->near_clip = 0.1f;
    this->far_clip = 800.0f;
    this->front = glm::vec3(0.0f, 0.0f, -1.0f);
    this->up = glm::vec3(0.0f, 1.0f, 0.0f);
}

void Camera::Update()
{
    glm::vec3 frontDirection;
    frontDirection.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));// * sin(glm::radians(roll));
    frontDirection.y = sin(glm::radians(pitch));// * cos(glm::radians(roll));
    frontDirection.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
    front = glm::normalize(frontDirection);

    view = glm::lookAt(position, position + front, up);
    projection = glm::perspective(fov, window->width / window->height, near_clip, far_clip);
}

void Camera::Render()
{
    GLuint modelLoc = glGetUniformLocation(SceneObject::defaultShader.program, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    GLuint viewLoc = glGetUniformLocation(SceneObject::defaultShader.program, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    GLuint projectionLoc = glGetUniformLocation(SceneObject::defaultShader.program, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

void Camera::SetFoV(float fov)
{
    this->fov = fov;
}

void Camera::SetClip(float near_clip, float far_clip)
{
    this->near_clip = near_clip;
    this->far_clip  = far_clip;
}

void Camera::SetPositionX(float x)
{
    position.x = x;
}

void Camera::SetPositionY(float y)
{
    position.y = y;
}

void Camera::SetPositionZ(float z)
{
    position.z = z;
}

void Camera::SetPosition(float x, float y, float z)
{
    position = glm::vec3(x, y, z);
}

void Camera::TranslateX(float a)
{
    position += glm::normalize(glm::cross(front, up)) * a;
}

void Camera::TranslateY(float a)
{
    position += up * a;
}

void Camera::TranslateZ(float a)
{
    position += front * a;
}

void Camera::Translate(float x, float y, float z)
{
    TranslateX(x);
    TranslateY(y);
    TranslateZ(z);
}

void Camera::SetRotationX(float x)
{
    pitch = x;
}

void Camera::SetRotationY(float y)
{
    yaw = y;
}

void Camera::SetRotationZ(float z)
{
    roll = z;
}

void Camera::SetRotation2(float x, float y)
{
    pitch = x;
    yaw   = y;
}

void Camera::SetRotation(float x, float y, float z)
{
    pitch = x;
    yaw   = y;
    roll  = z;
}

void Camera::SetPitch(float pitch)
{
    this->pitch = pitch;
}

void Camera::SetYaw(float yaw)
{
    this->yaw = yaw;
}

void Camera::SetRoll(float roll)
{
    this->roll = roll;
}

void Camera::RotateX(float x)
{
    pitch += x;
}

void Camera::RotateY(float y)
{
    yaw += y;
}

void Camera::RotateZ(float z)
{
    roll += z;
}

void Camera::Rotate(float x, float y, float z)
{
    pitch += x;
    yaw += y;
    roll += z;
}

void Camera::Rotate2(float x, float y)
{
    pitch += x;
    yaw += y;
}

Vector2 Camera::GetRotation2()
{
    return Vector2(pitch, yaw);
}
}
