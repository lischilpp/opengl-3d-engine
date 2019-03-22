#include "../headers/Texture.h"

Texture::Texture() {}

void Texture::load(const char* src, int width, int height) {
    unsigned char* image = SOIL_load_image(src, &width, &height, 0, SOIL_LOAD_RGBA);
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);

    this->width  = width;
    this->height = height;
}

void Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::update() {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}
