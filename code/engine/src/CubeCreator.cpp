#include "../headers/CubeCreator.h"

Texture CubeCreator::defaultTexture;

const GLuint CubeCreator::defaultTriangleOrder[6] = { 0, 1, 3,
                                                      1, 2, 3
                                                    };

const glm::vec2 CubeCreator::defaultUVOrder[4] = { glm::vec2(0.0f, 0.0f),
                                                   glm::vec2((float)Settings::uvUnit, 0.0f),
                                                   glm::vec2((float)Settings::uvUnit, (float)Settings::uvUnit),
                                                   glm::vec2(0.0f, (float)Settings::uvUnit)
                                                 };

const glm::vec3 CubeCreator::defaultNormals[6] = { glm::vec3(-1.0f,  0.0f,  0.0f),
                                                   glm::vec3( 1.0f,  0.0f,  0.0f),
                                                   glm::vec3( 0.0f, -1.0f,  0.0f),
                                                   glm::vec3( 0.0f,  1.0f,  0.0f),
                                                   glm::vec3( 0.0f,  0.0f, -1.0f),
                                                   glm::vec3( 0.0f,  0.0f,  1.0f)
                                                 };

CubeCreator::CubeCreator()
{
    triangleCount = 0;
}

void CubeCreator::setDefaultTexture(Texture texture)
{
    CubeCreator::defaultTexture = texture;
}

void CubeCreator::setOffset(glm::vec3 offset)
{
    this->offset = offset;
}

void CubeCreator::addVertex(glm::vec3 position, glm::vec3 normal, glm::vec3 color, glm::vec2 uv)
{
    Vertex vertex;
    vertex.position = position;
    vertex.normal   = normal;
    vertex.color    = color;
    vertex.uv       = uv;
    mesh.vertices.push_back(vertex);
}

void CubeCreator::addVertices(float verts[12], glm::vec3 normal, glm::vec3 color, glm::vec2 uvPos)
{
    int i, v;
    for (i = 0; i < 4; i++)
    {
        v = i * 3;
        addVertex(glm::vec3(verts[v]   + offset.x,
                            verts[v+1] + offset.y,
                            verts[v+2] + offset.z),
                  normal,
                  color,
                  glm::vec2(uvPos.x + defaultUVOrder[i].x, uvPos.y + defaultUVOrder[i].y));
    }
}

void CubeCreator::addTriangles()
{
    for (int i = 0; i < 6; i++)
    {
        mesh.triangles.push_back(triangleCount + CubeCreator::defaultTriangleOrder[i]);
    }
    triangleCount += 4;
}

void CubeCreator::left(glm::vec3 position, glm::vec3 color, int blockId)
{
    float verts[12] =
    {
        position.x, position.y,        position.z - 1.0f,
        position.x, position.y,        position.z,
        position.x, position.y + 1.0f, position.z,
        position.x, position.y + 1.0f, position.z - 1.0f
    };
    addVertices(verts, defaultNormals[0], color, Blocks::block[blockId - 1].left.uvPos);
    addTriangles();
}

void CubeCreator::right(glm::vec3 position, glm::vec3 color, int blockId)
{
    float verts[12] =
    {
        position.x + 1.0f,  position.y,        position.z,
        position.x + 1.0f,  position.y,        position.z - 1.0f,
        position.x + 1.0f,  position.y + 1.0f, position.z - 1.0f,
        position.x + 1.0f,  position.y + 1.0f, position.z
    };
    addVertices(verts, defaultNormals[1], color, Blocks::block[blockId - 1].right.uvPos);
    addTriangles();
}

void CubeCreator::bottom(glm::vec3 position, glm::vec3 color, int blockId)
{
    float verts[12] =
    {
        position.x,        position.y,             position.z - 1.0f,
        position.x + 1.0f, position.y,             position.z - 1.0f,
        position.x + 1.0f, position.y, position.z,
        position.x,        position.y, position.z
    };
    addVertices(verts, defaultNormals[2], color, Blocks::block[blockId - 1].bottom.uvPos);
    addTriangles();
}

void CubeCreator::top(glm::vec3 position, glm::vec3 color, int blockId)
{
    float verts[12] =
    {
        position.x,        position.y + 1.0f, position.z,
        position.x + 1.0f, position.y + 1.0f, position.z,
        position.x + 1.0f, position.y + 1.0f, position.z - 1.0f,
        position.x,        position.y + 1.0f, position.z - 1.0f
    };
    addVertices(verts, defaultNormals[3], color, Blocks::block[blockId - 1].top.uvPos);
    addTriangles();
}

void CubeCreator::front(glm::vec3 position, glm::vec3 color, int blockId)
{
    float verts[12] =
    {
        position.x + 1.0f, position.y,        position.z - 1.0f,
        position.x,        position.y,        position.z - 1.0f,
        position.x,        position.y + 1.0f, position.z - 1.0f,
        position.x + 1.0f, position.y + 1.0f, position.z - 1.0f
    };
    addVertices(verts, defaultNormals[4], color, Blocks::block[blockId - 1].front.uvPos);
    addTriangles();
}

void CubeCreator::back(glm::vec3 position, glm::vec3 color, int blockId)
{
    float verts[12] =
    {
        position.x,        position.y,        position.z,
        position.x + 1.0f, position.y,        position.z,
        position.x + 1.0f, position.y + 1.0f, position.z,
        position.x,        position.y + 1.0f, position.z
    };
    addVertices(verts, defaultNormals[5], color, Blocks::block[blockId - 1].back.uvPos);
    addTriangles();
}

void CubeCreator::clearData()
{
    mesh.vertices.clear();
    mesh.triangles.clear();
    triangleCount = 0;
}
