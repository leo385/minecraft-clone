#include "MouseController.h"
#include "MouseCoords.h"

#define UNUSED(x) (void)(x)

void MouseController::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	UNUSED(window);
	
	MouseCoords::xpos = xpos;
	MouseCoords::ypos = ypos;

}
