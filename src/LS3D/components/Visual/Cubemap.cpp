#include "Cubemap.h"

namespace Visual
{
void Cubemap::MapToCube(Visual::Mesh* cube)
{
    float third =  0.33333333f;
    float third2 = 0.66666666f;
    cube->uv.Add({
                   0.0f,  third, // left
                   0.25f, third,
                   0.25f, third2,
                   0.0f,  third2,
                   0.5f,  third, // right
                   0.75f, third,
                   0.75f, third2,
                   0.5f,  third2,
                   0.25f, 0.0f,  // bottom
                   0.5f,  0.0f,
                   0.5f,  third,
                   0.25f, third,
                   0.25f, third2, // top
                   0.5f,  third2,
                   0.5f,  1.0f,
                   0.25f, 1.0f,
                   0.75f, third, // back
                   1.0f,  third,
                   1.0f,  third2,
                   0.75f, third2,
                   0.25f, third,// front
                   0.5f,  third,
                   0.5f,  third2,
                   0.25f, third2

                    });
}
}
