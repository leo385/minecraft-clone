#pragma once

#include "BuffersObjectUnit.h"


class BuffersObjectController {

private:
	BuffersObjectUnit bufferUnit;

public:

	void generateBuffers();
	void deleteBuffers();
	
	void bindVAO();
	void unbindVAO();

	void bindVBO(GLsizeiptr size, const void* data);
	void bindEBO(GLsizeiptr size, const void* data);

	void enableVertexAttribPointer(GLuint index);

	GLuint getVAO();
	GLuint getVBO();
	GLuint getEBO();
};