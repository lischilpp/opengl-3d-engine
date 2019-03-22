#include <SOIL/SOIL.h>
#include <GL/glew.h>

class Texture
{
public:
    GLuint id;
    int width;
    int height;

    Texture();
    void load(const char* src, int width, int height);
    void bind();
    void update();
};
