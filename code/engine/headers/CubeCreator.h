using namespace std;
#include <GLM/glm.hpp>
#include "../../utility/headers/Mesh.h"
#include "../../utility/headers/Texture.h"
#include "Blocks.h"

class CubeCreator
{
public:
    static Texture defaultTexture;

    Mesh mesh;

    CubeCreator();

    static void setDefaultTexture(Texture texture);

    static const GLuint defaultTriangleOrder[6];
    static const glm::vec2 defaultUVOrder[4];
    static const glm::vec3 defaultNormals[6];

    void setOffset(glm::vec3 offset);
    void left(  glm::vec3 position, glm::vec3 color, int blockId);
    void right( glm::vec3 position, glm::vec3 color, int blockId);
    void front( glm::vec3 position, glm::vec3 color, int blockId);
    void back(  glm::vec3 position, glm::vec3 color, int blockId);
    void bottom(glm::vec3 position, glm::vec3 color, int blockId);
    void top(   glm::vec3 position, glm::vec3 color, int blockId);
    void clearData();



private:
    float voxelSize;
    glm::vec3 offset;
    vector<Vertex> vertices;
    vector<GLuint> triangles;
    GLuint triangleCount;
    void addVertex(glm::vec3 position, glm::vec3 normal, glm::vec3 color, glm::vec2 uv);
    void addVertices(float verts[8], glm::vec3 normal, glm::vec3 color, glm::vec2 uvPos);
    void addTriangles();
};
