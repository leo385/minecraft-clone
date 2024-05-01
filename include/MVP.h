#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct MVP {
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	glm::mat4 modelViewProjection;

	void init();
	void setMat4(unsigned int programID, const char* mvpTitle);
};