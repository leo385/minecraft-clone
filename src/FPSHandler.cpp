#include "FPSHandler.h"

#include "GLFW/glfw3.h"

float FPSHandler::calculateFps()
{
	currentTime = (float)glfwGetTime();
	frameCount++;

	if (currentTime - lastTime >= 1.0f) {

		fps = frameCount / (currentTime - lastTime);
		lastTime = currentTime;
		frameCount = 0;
	}

	return fps;
}
