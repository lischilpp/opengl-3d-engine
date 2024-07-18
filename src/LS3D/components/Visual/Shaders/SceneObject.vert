#version 330 core
layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 uv;

// camera
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
// object
uniform mat4 transform;
uniform mat4 rotation;

out vec3 Color;
out vec2 UV;

void main()
{
    gl_Position = projection * view * model * transform * rotation * vec4(vertex, 1.0f);
    Color = (color != vec3(0,0,0)) ? color : vec3(1.0f, 1.0f, 1.0f);
    UV = uv;
}
