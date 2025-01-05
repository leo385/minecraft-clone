#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Scene.h"
#include "GuiHandler.h"

#include <memory>


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
	
	std::unique_ptr<Window> window;
	std::unique_ptr<Scene> scene;
	std::unique_ptr<GuiHandler> gui;

};
