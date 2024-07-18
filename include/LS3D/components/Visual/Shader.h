#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

namespace Visual
{
class Shader
{
public:
    static string defaultPath;
    static void SetDefaultPath(string path);
    GLuint program;
    void Use();
    GLuint GetUniformLocation(const char* name);
    void Load(string vertex_path, string fragment_path);
};
}
