#pragma once
#include "Mesh.h"

namespace Visual {
class GeometryCreator
{
public:
    void PlaneXYBack(Mesh* mesh, float w, float h);
    void PlaneXYFront(Mesh* mesh, float w, float h);
    void PlaneYZRight(Mesh* mesh, float h, float d);
    void PlaneXZDown(Mesh* mesh, float w, float d);
    void PlaneXZUp(Mesh* mesh, float w, float d);
    void Cuboid(Mesh* mesh, float w, float h, float d);
    void CuboidInverted(Mesh* mesh, float w, float h, float d);
    void Cube(Mesh* mesh, float s);
    void CubeInverted(Mesh* mesh, float s);
};
}
