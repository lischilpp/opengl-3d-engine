#version 330 core

in vec3 Color;
in vec2 UV;

uniform sampler2D ourTexture;

out vec4 color;

void main()
{
    color = vec4(Color, 1.0f) * texture(ourTexture, vec2(UV.x, 1.0f - UV.y));
}
