#include "LS3D/components/Visual/GeometryCreator.h"

namespace Visual
{

    void GeometryCreator::PlaneXYBack(Mesh* mesh, float w, float h)
{
    float hw = w * 0.5f,
          hh = h * 0.5f;

    mesh->vertices.Add({  hw, -hh, 0.0f,
                         -hw, -hh, 0.0f,
                         -hw,  hh, 0.0f,
                          hw,  hh, 0.0f });

    mesh->triangles.Add({ 0, 1, 3,
                          1, 2, 3 });
}

void GeometryCreator::PlaneXYFront(Mesh* mesh, float w, float h)
{
    float hw = w * 0.5f,
          hh = h * 0.5f;

    mesh->vertices.Add({ -hw, -hh, 0.0f,
                          hw, -hh, 0.0f,
                          hw,  hh, 0.0f,
                         -hw,  hh, 0.0f });

    mesh->triangles.Add({ 0, 1, 3,
                          1, 2, 3 });
}

void GeometryCreator::PlaneXZDown(Mesh* mesh, float w, float d)
{
    float hw = w * 0.5f,
          hd = d * 0.5f;

    mesh->vertices.Add({ -hw, 0.0f, -hd,
                          hw, 0.0f, -hd,
                          hw, 0.0f,  hd,
                         -hw, 0.0f,  hd });

    mesh->triangles.Add({ 0, 1, 3,
                          1, 2, 3 });
}

void GeometryCreator::PlaneXZUp(Mesh* mesh, float w, float d)
{
    float hw = w * 0.5f,
          hd = d * 0.5f;

    mesh->vertices.Add({ -hw, 0.0f,  hd,
                          hw, 0.0f,  hd,
                          hw, 0.0f, -hd,
                         -hw, 0.0f, -hd });

    mesh->triangles.Add({ 0, 1, 3,
                          1, 2, 3 });
}

void GeometryCreator::PlaneYZRight(Mesh* mesh, float h, float d)
{
    float hh = h * 0.5f,
          hd = d * 0.5f;

    mesh->vertices.Add({  0.0f, -hh,  hd,
                          0.0f, -hh, -hd,
                          0.0f,  hh, -hd,
                          0.0f,  hh,  hd });

    mesh->triangles.Add({ 0, 1, 3,
                          1, 2, 3 });
}


void GeometryCreator::Cuboid(Mesh* mesh, float w, float h, float d)
{
    float hw = w * 0.5f,
          hh = h * 0.5f,
          hd = d * 0.5f;

    mesh->vertices.Add({ -hw, -hh, -hd, // left
                         -hw, -hh,  hd,
                         -hw,  hh,  hd,
                         -hw,  hh, -hd,
                          hw, -hh,  hd, // right
                          hw, -hh, -hd,
                          hw,  hh, -hd,
                          hw,  hh,  hd,
                         -hw, -hh, -hd, // bottom
                          hw, -hh, -hd,
                          hw, -hh,  hd,
                         -hw, -hh,  hd,
                         -hw,  hh,  hd, // top
                          hw,  hh,  hd,
                          hw,  hh, -hd,
                         -hw,  hh, -hd,
                          hw, -hh, -hd, // back
                         -hw, -hh, -hd,
                         -hw,  hh, -hd,
                          hw,  hh, -hd,
                         -hw, -hh,  hd, // front
                          hw, -hh,  hd,
                          hw,  hh,  hd,
                         -hw,  hh,  hd });

    mesh->triangles.Add({ 12, 13, 15, // left
                          13, 14, 15,
                          8,   9, 11, // right
                          9,  10, 11,
                          20, 21, 23, // bottom
                          21, 22, 23,
                          16, 17, 19, // top
                          17, 18, 19,
                          4,   5,  7, // back
                          5,   6,  7,
                          0,   1,  3, // front
                          1,   2,  3 });

    /*mesh->normals.Add({ -1.0f,  0.0f,  0.0f, // left
                        -1.0f,  0.0f,  0.0f,
                        -1.0f,  0.0f,  0.0f,
                        -1.0f,  0.0f,  0.0f,
                         1.0f,  0.0f,  0.0f, // right
                         1.0f,  0.0f,  0.0f,
                         1.0f,  0.0f,  0.0f,
                         1.0f,  0.0f,  0.0f,
                         0.0f, -1.0f,  0.0f, // bottom
                         0.0f, -1.0f,  0.0f,
                         0.0f, -1.0f,  0.0f,
                         0.0f, -1.0f,  0.0f,
                         0.0f,  1.0f,  0.0f, // top
                         0.0f,  1.0f,  0.0f,
                         0.0f,  1.0f,  0.0f,
                         0.0f,  1.0f,  0.0f,
                         0.0f,  0.0f, -1.0f, // back
                         0.0f,  0.0f, -1.0f,
                         0.0f,  0.0f, -1.0f,
                         0.0f,  0.0f, -1.0f,
                         0.0f,  0.0f,  1.0f, // front
                         0.0f,  0.0f,  1.0f,
                         0.0f,  0.0f,  1.0f,
                         0.0f,  0.0f,  1.0f });*/
}

void GeometryCreator::CuboidInverted(Mesh* mesh, float w, float h, float d)
{
    float hw = w * 0.5f,
          hh = h * 0.5f,
          hd = d * 0.5f;

    mesh->vertices.Add({ -hw, -hh, -hd, // left
                         -hw, -hh,  hd,
                         -hw,  hh,  hd,
                         -hw,  hh, -hd,
                          hw, -hh,  hd, // right
                          hw, -hh, -hd,
                          hw,  hh, -hd,
                          hw,  hh,  hd,
                         -hw, -hh, -hd, // bottom
                          hw, -hh, -hd,
                          hw, -hh,  hd,
                         -hw, -hh,  hd,
                         -hw,  hh,  hd, // top
                          hw,  hh,  hd,
                          hw,  hh, -hd,
                         -hw,  hh, -hd,
                          hw, -hh, -hd, // back
                         -hw, -hh, -hd,
                         -hw,  hh, -hd,
                          hw,  hh, -hd,
                         -hw, -hh,  hd, // front
                          hw, -hh,  hd,
                          hw,  hh,  hd,
                         -hw,  hh,  hd });

    mesh->triangles.Add({ 3,   1,  0, // left
                          3,   2,  1,
                          7,   5,  4, // right
                          7,   6,  5,
                          11,  9,  8, // bottom
                          11, 10,  9,
                          15, 13, 12, // top
                          15, 14, 13,
                          19, 17, 16, // back
                          19, 18, 17,
                          23, 21, 20, // front
                          23, 22, 21 });
}

void GeometryCreator::Cube(Mesh* mesh, float s)
{
    Cuboid(mesh, s, s, s);
}

void GeometryCreator::CubeInverted(Mesh* mesh, float s)
{
    CuboidInverted(mesh, s, s, s);
}
}
