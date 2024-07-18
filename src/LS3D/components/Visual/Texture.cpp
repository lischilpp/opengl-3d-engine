#include "Texture.h"
#include <iostream>
#include <fstream>

namespace Visual
{

void Texture::Load(const char* src, int width, int height)
{
    this->width = width;
    this->height = height;

    // Allocate memory for the image
    unsigned char* image = new unsigned char[width * height * 4]; // RGBA

    // Open the file
    std::ifstream file(src, std::ios::binary);
    if (!file)
    {
        std::cerr << "Failed to open image file: " << src << std::endl;
        delete[] image;
        return;
    }

    // Read the image data
    file.read(reinterpret_cast<char*>(image), width * height * 4);
    if (!file)
    {
        std::cerr << "Failed to read image file: " << src << std::endl;
        delete[] image;
        return;
    }
    file.close();

    // Generate and bind the texture
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Free the image memory
    delete[] image;
    glBindTexture(GL_TEXTURE_2D, 0);

    this->loaded = true;
}

void Texture::Use()
{
    if (loaded)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D, id);
    }
}
}
