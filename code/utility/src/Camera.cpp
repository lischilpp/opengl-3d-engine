#include "../headers/Camera.h"
#include <iostream>
#include "../headers/Input.h"

Camera::Camera(float window_width, float window_height, GLuint shader_program, vec3 position) {
    this->window_width   = window_width;
    this->window_height  = window_height;
    this->shader_program = shader_program;
    this->position       = position;

    this->up = vec3(0.0f, 1.0f, 0.0f);
    this->front = vec3(0.0f, 0.0f, -1.0f);
    this->moveSpeed =  32.0f;
    this->yaw = 270.0f;
    this->pitch = 0.0f;

}

void Camera::update()
{
    glm::vec3 frontDirection;
    frontDirection.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
    frontDirection.y = sin(glm::radians(pitch));
    frontDirection.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
    front = glm::normalize(frontDirection);

    mat4 model;
    // view
    mat4 view;

    view = lookAt(position, position + front, up);
    // projection
    mat4 projection;
    projection = perspective(45.0f, window_width / window_height, 0.1f, 800.0f);

    GLuint modelLoc = glGetUniformLocation(shader_program, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));

    GLuint viewLoc = glGetUniformLocation(shader_program, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, value_ptr(view));

    GLuint projectionLoc = glGetUniformLocation(shader_program, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, value_ptr(projection));

    GLint viewPosLoc = glGetUniformLocation(shader_program, "viewPos");
    glUniform3f(viewPosLoc, this->position.x, this->position.y, this->position.z);
}

void Camera::moveX(float amount) {
    position += glm::normalize(glm::cross(front, up)) * amount;
}

void Camera::moveY(float amount) {
    position += up * amount;
}

void Camera::moveZ(float amount) {
    position += front * amount;
}
