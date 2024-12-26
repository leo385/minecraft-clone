#include "CameraMoving.h"
#include "MouseCoords.h"

#include <GLFW/glfw3.h>

CameraMoving::CameraMoving()
{
	yaw = -90.0f;
	pitch = 0.0f;

	sensitivity = 0.10f;
}


void CameraMoving::moveCameraWithMouse(const IWindow& window, Camera& camera)
{
	
	static bool firstMouse = true;

	static float xpos = 960.0f;
	static float ypos = 540.0f;

	bool isWindowFocused = window.getFocused();

	double currentX, currentY;
	glfwGetCursorPos(window.getWindow(), &currentX, &currentY);

	if (!isWindowFocused) {

		firstMouse = true;
	}
	
	if (firstMouse) {

		xpos = static_cast<float>(currentX);
		ypos = static_cast<float>(currentY);

		firstMouse = false;

	}

	float xoffset = static_cast<float>(currentX) - xpos;
	float yoffset = ypos - static_cast<float>(currentY);

	xpos = static_cast<float>(currentX);
	ypos = static_cast<float>(currentY);

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
