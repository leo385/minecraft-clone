#pragma once

#include <GLFW/glfw3.h>

#include "IWindow.h"
#include "MouseController.h"

#include <memory>

class Window : public IWindow{

public:
	Window() = default;
	~Window();

	// IWindow methods
	int getWidth() const override;
	int getHeight() const override;

	GLFWwindow* getWindow() const override;

	bool initialize();

	void setOpenGLVersion();
	void createWindow(int width, int height);
	void makeContextCurrentFrame();
	void setFrameBufferSizeCallback();

	void setCursorHidden();
	void setCursorPositionCallback();

	int windowShouldClose();

	void swapBuffers();
	void destroyWindow();
	

private:
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	GLFWwindow* window{ nullptr };

	int _width;
	int _height;
	
};