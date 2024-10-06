#pragma once

#include "BuffersObjectUnit.h"


class BuffersObjectController {

private:
	BuffersObjectUnit bufferUnit;

public:

	void generateBuffers();
	void deleteBuffers();
	
	void bindVAO();
	void bindVBO(GLsizeiptr size, const void* data);
	void bindEBO(GLsizeiptr size, const void* data);

	void unbindVBO();
	void unbindVAO();

	void setVertexAttribPointer(GLuint index, GLint size, GLsizei stride, int steps);
	void enableVertexAttribPointer(GLuint index);

	GLuint getVAO();
	GLuint getVBO();
	GLuint getEBO();
};