#pragma once

#include <GL/glew.h>

class Texture
{
private:
	int width;
	int height;
	int nrChannels;

public:
	Texture() = default;

	void init(GLuint* textureID, GLenum activeTexture);
	void setTextureParameter(int textureMode, int min_filtering_mode, int mag_filtering_mode);
	void loadTextureIntoGL(const char* filename);
	void sendTextureToShader(const unsigned int& shaderID, const char* uniform_name, int slot);
	void unbindTexture();

};

