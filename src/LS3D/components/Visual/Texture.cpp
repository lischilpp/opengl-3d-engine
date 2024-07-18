#include <iostream>
#include <fstream>
#define STB_IMAGE_IMPLEMENTATION
#include "../../../../lib/stb_image.h"

#include "Texture.h"

namespace Visual
{

void Texture::Load(const char* src, int width, int height)
{
    this->width = width;
    this->height = height;

    // Load image using stb_image
    unsigned char* image = stbi_load(src, &width, &height, nullptr, 4); // RGBA
    if (!image)
    {
        std::cerr << "Failed to load image file: " << src << std::endl;
        return;
    }

    // Generate and bind the texture
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Free stb_image allocated memory
    stbi_image_free(image);

    // Set loaded flag to true
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

} // namespace Visual
