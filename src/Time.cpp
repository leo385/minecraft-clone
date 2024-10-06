#include "Time.h"

#include <GLFW/glfw3.h>

float Time::lastFrame = 0.0f;

float Time::getDeltaTime()
{
    float deltaTime = 0.0f;
    float currentFrame = (float)glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    return deltaTime;
}
