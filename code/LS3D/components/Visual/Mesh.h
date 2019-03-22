#pragma once
#include <GL/glew.h>
#include <vector>
#include "../Types/Vector3.h"
#include "../Types/StorageVector.h"

#define VERTEX_BUFFER 0
#define COLOR_BUFFER 1
#define NORMAL_BUFFER 2
#define UV_BUFFER 3

namespace Visual
{
class Mesh
{
public:
    StorageVector<float> vertices;
    StorageVector<float> colors;
    StorageVector<float> normals;
    StorageVector<float> uv;
    StorageVector<GLuint> triangles;
    void Push();
    void Render();
    ~Mesh();
private:
    GLuint VAO, EBO;
    GLuint Buffers[4];
    int triangleCount;
};
}
