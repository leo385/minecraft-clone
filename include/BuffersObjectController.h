#pragma once

#include "BuffersObjectUnit.h"


class BuffersObjectController {

private:
	BuffersObjectUnit bufferUnit;

public:

	void generateVAO(GLuint& vao);
	void generateVBO(GLuint& vbo);
	void generateEBO();

	void deleteVAO(GLuint& vao);
	void deleteVBO(GLuint& vbo);
	void deleteEBO();
	
	void bindVAO(GLuint& vao);
	void bindVBO(GLuint& vbo, GLsizeiptr size, const void* data);
	void bindEBO(GLsizeiptr size, const void* data);

	void unbindVBO();
	void unbindVAO();

	void setVertexAttribPointer(GLuint index, GLint size, GLsizei stride, int steps);
	void setVertexAttribDivisor(GLuint index, GLuint divisor);

	void enableVertexAttribPointer(GLuint index);

	GLuint getVAO() const;
	GLuint getVBO() const;
	GLuint getEBO() const;
};