#include "Shader.h"

namespace Visual
{

string Shader::defaultPath = "";

void Shader::SetDefaultPath(string path)
{
    Shader::defaultPath = path;
}

void Shader::Load(string vertexPath, string fragmentPath)
{

    string vertexPathString = defaultPath + vertexPath;
    string fragmentPathString = defaultPath + fragmentPath;
    const char* vertex_path = vertexPathString.c_str();
    const char* fragment_path = fragmentPathString.c_str();

    // create shaders
    GLuint vertexShaderID   = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // read vertex shader to string
    string vertexShaderCode;
    ifstream vertexShaderStream(vertex_path, ios::in);
    if(vertexShaderStream.is_open())
    {
        string line = "";
        while(getline(vertexShaderStream, line))
            vertexShaderCode += "\n" + line;
        vertexShaderStream.close();
    }else {
        cout << "Failed to open shader file " << vertex_path << endl;
    }

    // read fragment shader to string
    string fragmentShaderCode;
    ifstream fragmentShaderStream(fragment_path, ios::in);
    if(fragmentShaderStream.is_open())
    {
        string line = "";
        while(getline(fragmentShaderStream, line))
            fragmentShaderCode += "\n" + line;
        fragmentShaderStream.close();
    }else {
        cout << "Failed to open shader file " << fragment_path << endl;
    }

    GLint result = GL_FALSE;
    int infoLogLength;

    // Compile Vertex Shader
    printf("Compiling shader : %s\n", vertex_path);
    char const* vertexSourcePointer = vertexShaderCode.c_str();
    glShaderSource(vertexShaderID, 1, &vertexSourcePointer , NULL);
    glCompileShader(vertexShaderID);

    // Check Vertex Shader
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
    vector<char> vertexShaderErrorMessage(infoLogLength);
    glGetShaderInfoLog(vertexShaderID, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &vertexShaderErrorMessage[0]);

    // Compile Fragment Shader
    printf("Compiling shader : %s\n", fragment_path);
    char const* fragmentSourcePointer = fragmentShaderCode.c_str();
    glShaderSource(fragmentShaderID, 1, &fragmentSourcePointer , NULL);
    glCompileShader(fragmentShaderID);

    // Check Fragment Shader
    glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
    vector<char> fragmentShaderErrorMessage(infoLogLength);
    glGetShaderInfoLog(fragmentShaderID, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &fragmentShaderErrorMessage[0]);

    // Link the program
    fprintf(stdout, "Linking program\n");
    program = glCreateProgram();
    glAttachShader(program, vertexShaderID);
    glAttachShader(program, fragmentShaderID);
    glLinkProgram(program);

    // Check the program
    glGetProgramiv(program, GL_LINK_STATUS, &result);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
    vector<char> programErrorMessage( max(infoLogLength, int(1)) );
    glGetProgramInfoLog(program, infoLogLength, NULL, &programErrorMessage[0]);
    fprintf(stdout, "%s\n", &programErrorMessage[0]);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

void Shader::Use()
{
    glUseProgram(program);
}

GLuint Shader::GetUniformLocation(const char* name)
{
    return glGetUniformLocation(program, name);
}
}
