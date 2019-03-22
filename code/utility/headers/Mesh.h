#include <GL/glew.h>
#include <GLM/glm.hpp>
#include <vector>
#include "Shader.h"
using namespace std;

struct Vertex {
    glm::vec3 position, normal, color;
    glm::vec2 uv;
};

class Mesh
{
public:
    vector<Vertex> vertices;
    vector<GLuint> triangles;
    void render();
    void renderLines();
    void push();
private:
    GLuint VAO, VBO, EBO;
    int triangleCount;
};
