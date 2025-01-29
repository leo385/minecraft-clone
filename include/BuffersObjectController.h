#pragma once

#include "BuffersObjectUnit.h"


class BuffersObjectController {

private:
	BuffersObjectUnit bufferUnit;

public:

	void generateVAO(GLuint& vao);
	void generateVBO(GLuint& vbo);
	void generateEBO(GLuint& ebo);

	void deleteVAO(GLuint& vao);
	void deleteVBO(GLuint& vbo);
	void deleteEBO(GLuint& ebo);
	
	void bindVAO(GLuint& vao);
	void bindVBO(GLuint& vbo, GLsizeiptr size, const void* data);
	void bindEBO(GLuint& ebo, GLsizeiptr size, const void* data);

	void unbindEBO();
	void unbindVBO();
	void unbindVAO();

	void setVertexAttribPointer(GLuint index, GLint size, GLsizei stride, int steps);
	void setVertexAttribDivisor(GLuint index, GLuint divisor);

	void enableVertexAttribPointer(GLuint index);

	GLuint getVAO() const;
	GLuint getVBO() const;
	GLuint getEBO() const;
};