#pragma once

#include <GL\glew.h>
#include <GLFW/glfw3.h>

#include <Shader.h>

class Application {

public:

	Application();
	~Application();

	bool Initialize();
	void Run();
	void Terminate();

private:
	void MainLoop();
	void Render();
	

	GLFWwindow* window;
	
};