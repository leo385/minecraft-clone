#include "CameraMoving.h"
#include "MouseCoords.h"

CameraMoving::CameraMoving()
{
	// Mouse that has moved first time
	firstMouse = true;

	lastX = 400.0f;
	lastY = 300.0f;

	yaw = -90.0f;
	pitch = 0.0f;

	sensitivity = 0.1f;
}

void CameraMoving::moveCameraWithMouse(Camera& camera)
{
	float xpos = static_cast<float>(MouseCoords::xpos);
	float ypos = static_cast<float>(MouseCoords::ypos);

	if (firstMouse) {

		lastX = xpos;
		lastY = ypos;

		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;

	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;

	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	camera.setDirection(glm::normalize(direction));
}
