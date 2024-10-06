#include "BuffersObjectController.h"


void BuffersObjectController::generateBuffers()
{
	glGenVertexArrays(1, &bufferUnit.VAO);
	glGenBuffers(1, &bufferUnit.VBO);
	glGenBuffers(1, &bufferUnit.EBO);
}

void BuffersObjectController::deleteBuffers()
{
	glDeleteVertexArrays(1, &bufferUnit.VAO);
	glDeleteBuffers(1, &bufferUnit.VBO);
	glDeleteBuffers(1, &bufferUnit.EBO);
}

void BuffersObjectController::bindVAO()
{
	glBindVertexArray(bufferUnit.VAO);
}

void BuffersObjectController::unbindVBO()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void BuffersObjectController::unbindVAO()
{
	glBindVertexArray(0);
}

void BuffersObjectController::bindVBO(GLsizeiptr size, const void* data)
{
	glBindBuffer(GL_ARRAY_BUFFER, bufferUnit.VBO);
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

void BuffersObjectController::enableVertexAttribPointer(GLuint index)
{
	glEnableVertexAttribArray(index);
}

GLuint BuffersObjectController::getVAO()
{
	return bufferUnit.VAO;
}

GLuint BuffersObjectController::getVBO()
{
	return bufferUnit.VBO;
}

GLuint BuffersObjectController::getEBO()
{
	return bufferUnit.EBO;
}
