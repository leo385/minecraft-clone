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

void BuffersObjectController::enableVertexAttribPointer(GLuint index)
{
	glVertexAttribPointer(index, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
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
