#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Shader
{
public:
    void use();
    GLuint getUniformLocation(const char* name);
    GLuint getProgram();
    Shader(const char* vertex_path, const char* fragment_path);
private:
    GLuint program;
};

