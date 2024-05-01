#include "MVP.h"

#include <GL/glew.h>


void MVP::init()
{
	model = glm::mat4(1.0f);
	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);
	modelViewProjection = glm::mat4(1.0f);
}

void MVP::setMat4(unsigned int programID, const char* mvpTitle)
{
	unsigned int mvpLocationID = glGetUniformLocation(programID, mvpTitle);
	glUniformMatrix4fv(mvpLocationID, 1, GL_FALSE, glm::value_ptr(modelViewProjection));
}
