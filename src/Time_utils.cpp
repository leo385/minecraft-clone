#include "Time_utils.h"


#include <GLFW/glfw3.h>

float Time_utils::lastFrame = 0.0f;

float Time_utils ::getDeltaTime()
{
    float deltaTime = 0.0f;
    float currentFrame = (float)glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    return deltaTime;
}
