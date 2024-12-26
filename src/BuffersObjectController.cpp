#include "BuffersObjectController.h"


void BuffersObjectController::generateVAO(GLuint& vao)
{
	glGenVertexArrays(1, &vao);
}

void BuffersObjectController::generateVBO(GLuint& vbo)
{
	glGenBuffers(1, &vbo);
}

void BuffersObjectController::generateEBO()
{
	glGenBuffers(1, &bufferUnit.EBO);
}

void BuffersObjectController::deleteVAO(GLuint& vao)
{
	glDeleteVertexArrays(1, &vao);
}

void BuffersObjectController::deleteVBO(GLuint& vbo)
{
	glDeleteBuffers(1, &vbo);
}

void BuffersObjectController::deleteEBO()
{
	glDeleteBuffers(1, &bufferUnit.EBO);
}

void BuffersObjectController::unbindVBO()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void BuffersObjectController::unbindVAO()
{
	glBindVertexArray(0);
}

void BuffersObjectController::bindVAO(GLuint& vao)
{
	glBindVertexArray(vao);
}

void BuffersObjectController::bindVBO(GLuint& vbo, GLsizeiptr size, const void* data)
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void BuffersObjectController::bindEBO(GLsizeiptr size, const void* data)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferUnit.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void BuffersObjectController::setVertexAttribPointer(GLuint index, GLint size, GLsizei stride, int steps)
{
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(steps * sizeof(float)));
}

void BuffersObjectController::setVertexAttribDivisor(GLuint index, GLuint divisor)
{
	glVertexAttribDivisor(index, divisor);
}

void BuffersObjectController::enableVertexAttribPointer(GLuint index)
{
	glEnableVertexAttribArray(index);
}

GLuint BuffersObjectController::getVAO() const
{
	return bufferUnit.VAO;
}

GLuint BuffersObjectController::getVBO() const
{
	return bufferUnit.VBO;
}

GLuint BuffersObjectController::getEBO() const
{
	return bufferUnit.EBO;
}
