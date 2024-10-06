#include "Camera.h"
#include "Time.h"

#include <iostream>

void Camera::init()
{
	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

}

void Camera::handleInput(const IWindow& _window)
{
	float cameraSpeed = 2.5f * Time::getDeltaTime();

	//std::cout << Time::getDeltaTime() << "\n";

	if (glfwGetKey(_window.getWindow(), GLFW_KEY_W) == GLFW_PRESS) {
		cameraPos += cameraSpeed * cameraFront;
	}
	if (glfwGetKey(_window.getWindow(), GLFW_KEY_S) == GLFW_PRESS) {
		cameraPos -= cameraSpeed * cameraFront;
	}
	if (glfwGetKey(_window.getWindow(), GLFW_KEY_A) == GLFW_PRESS) {
		cameraPos -= cameraSpeed * glm::normalize(glm::cross(cameraFront, cameraUp));
	}
	if (glfwGetKey(_window.getWindow(), GLFW_KEY_D) == GLFW_PRESS) {
		cameraPos += cameraSpeed * glm::normalize(glm::cross(cameraFront, cameraUp));
	}
}

void Camera::setDirection(const glm::vec3& direction)
{
	cameraFront = direction;
}


glm::vec3 Camera::getCameraPos() const
{
	return cameraPos;
}

glm::vec3 Camera::getCameraFront() const
{
	return cameraFront;
}

glm::vec3 Camera::getCameraUp() const
{
	return cameraUp;
}

const Camera& Camera::getObject() const
{
	return *this;
}
