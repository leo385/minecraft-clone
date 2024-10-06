#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.h"
#include "MVP.h"


class Camera
{
private:
	glm::vec3 cameraPos{ 0 };
	glm::vec3 cameraFront{ 0 };
	glm::vec3 cameraUp{ 0 };

public:
	Camera() = default;

	void init();
	void handleInput(const IWindow& _window);
	void setDirection(const glm::vec3& direction);

	glm::vec3 getCameraPos() const;
	glm::vec3 getCameraFront() const;
	glm::vec3 getCameraUp() const;

	const Camera& getObject() const;
};

