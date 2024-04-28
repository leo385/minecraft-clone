#pragma once

#include <GLFW/glfw3.h>

#include "IWindow.h"

class Window : public IWindow{

public:
	Window() = default;
	~Window();

	// IWindow methods
	int getWidth() const override;
	int getHeight() const override;


	bool initialize();

	void setOpenGLVersion();
	void createWindow(int width, int height);
	void makeContextCurrentFrame();
	void setFrameBufferSizeCallback();

	int windowShouldClose();

	void swapBuffers();
	void destroyWindow();
	


private:
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	GLFWwindow* window{ nullptr };
	
	int _width;
	int _height;
	
};