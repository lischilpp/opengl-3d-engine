#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 uv;

out vec3 Color;
out vec3 FragPos;
out vec3 Normal;
out vec2 UV;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    Color = color;
    Normal = normal;
    gl_Position = projection * view * model * vec4(position, 1.0f);
    FragPos = position;
    UV = uv;
}
