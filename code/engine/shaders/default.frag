#version 330 core

uniform vec3 viewPos;
uniform sampler2D defaultTexture;

in vec3 Color;
in vec3 Normal;
in vec3 FragPos;
in vec2 UV;

out vec4 color;

vec3 lightPos = vec3(64, 128, 64);
vec3 lightColor = vec3(0.5, 0.5, 0.5);

void main()
{

    // Ambient
    float ambientStrength = 0.5f;
    vec3 ambient = ambientStrength * lightColor;

    // Diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // Specular
    float specularStrength = 2.0f;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient + diffuse + specular);
    color = texture(defaultTexture, UV) * vec4(result + Color, 1.0f);
}
