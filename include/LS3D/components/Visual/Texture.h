#pragma once
#include <GL/glew.h>

namespace Visual
{
class Texture
{
public:
    int width, height;
    bool loaded;
    void Load(const char* src, int width, int height);
    void Use();
private:
    GLuint id;
};
}
