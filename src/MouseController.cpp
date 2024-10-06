#include "MouseController.h"
#include "MouseCoords.h"

#include <iostream>

#define UNUSED(x) (void)(x)

static float lastX = 400.0f;
static float lastY = 300.0f;
static float yaw = -90.0f;
static float pitch = 0.0f;
static float sensitivity = 0.1f;

// Handle first mouse movement
static bool firstMouse = true;

void MouseController::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	UNUSED(window);
	
	MouseCoords::xpos = xpos;
	MouseCoords::ypos = ypos;

	//std::cout << "Position Mouse X: " << MouseCoords::xpos << "\n";
	//std::cout << "Position Mouse Y: " << MouseCoords::ypos << "\n";

}
