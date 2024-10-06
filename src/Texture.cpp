#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Texture.h"

#include <iostream>

void Texture::init(GLuint* textureID, GLenum activeTexture)
{
	// Assign texture id to texture object
	glGenTextures(1, textureID);
	glActiveTexture(activeTexture);
	glBindTexture(GL_TEXTURE_2D, *textureID);
}

void Texture::setTextureParameter(int textureMode, int min_filtering_mode, int mag_filtering_mode)
{
	//// set the texture wrapping/filtering options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, textureMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, textureMode);

	//// filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filtering_mode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filtering_mode);
}

void Texture::loadTextureIntoGL(const char* filename)
{
	unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);

	if (!data) {
		std::cout << "Failed to load texture" << "\n";
	}
	else {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	stbi_image_free(data);
}

void Texture::sendTextureToShader(const unsigned int& shaderID, const char* uniform_name, int slot)
{
	glUniform1i(glGetUniformLocation(shaderID, uniform_name), slot);
}

void Texture::unbindTexture()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
