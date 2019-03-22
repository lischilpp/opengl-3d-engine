#include "../headers/Mesh.h"

void Mesh::push()
{

    triangleCount = triangles.size();

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glBufferData(GL_ARRAY_BUFFER,
                 vertices.size() * sizeof(Vertex),
                 &vertices[0], GL_STATIC_DRAW);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 triangleCount * sizeof(GLuint),
                 &triangles[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(Vertex),
                          (GLvoid*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex, color));

    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3,
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex, uv));
}

void Mesh::render()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, triangleCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Mesh::renderLines()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_LINES, triangleCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
