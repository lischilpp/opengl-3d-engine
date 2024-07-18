#include "Mesh.h"
#include <iostream>

namespace Visual {

void Mesh::Push()
{

    triangleCount = triangles.Size();

    // generate buffers
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    // bind triangles
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, triangleCount * sizeof(GLuint),
                 &triangles[0], GL_STATIC_DRAW);

    // bind vertices

    // vertex position for layout location=0 (shader)
    glGenBuffers(1, &Buffers[VERTEX_BUFFER]);
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[VERTEX_BUFFER]);

    glBufferData(GL_ARRAY_BUFFER, vertices.Size() * sizeof(float),
                 &vertices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3,
                          (GLvoid*)0);


    if (colors.Size() > 0)
    {
        glGenBuffers(1, &Buffers[COLOR_BUFFER]);
        glBindBuffer(GL_ARRAY_BUFFER, Buffers[COLOR_BUFFER]);

        glBufferData(GL_ARRAY_BUFFER, colors.Size() * sizeof(float),
                     &colors[0], GL_STATIC_DRAW);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3,
                              (GLvoid*)0);
    }
    if (uv.Size() > 0)
    {
        glGenBuffers(1, &Buffers[UV_BUFFER]);
        glBindBuffer(GL_ARRAY_BUFFER, Buffers[UV_BUFFER]);

        glBufferData(GL_ARRAY_BUFFER, uv.Size() * sizeof(float),
                     &uv[0], GL_STATIC_DRAW);

        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2,
                              (GLvoid*)0);
    }
    if (normals.Size() > 0)
    {
        glGenBuffers(1, &Buffers[NORMAL_BUFFER]);
        glBindBuffer(GL_ARRAY_BUFFER, Buffers[NORMAL_BUFFER]);

        glBufferData(GL_ARRAY_BUFFER, normals.Size() * sizeof(float),
                     &normals[0], GL_STATIC_DRAW);

        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3,
                              (GLvoid*)0);
    }


    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


}

void Mesh::Render()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, triangleCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &Buffers[VERTEX_BUFFER]);
    glDeleteBuffers(1, &Buffers[COLOR_BUFFER]);
    glDeleteBuffers(1, &Buffers[NORMAL_BUFFER]);
    glDeleteBuffers(1, &Buffers[UV_BUFFER]);
    glDeleteBuffers(1, &EBO);
}

}
