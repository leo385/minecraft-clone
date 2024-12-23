#pragma once

#include <GLFW/glfw3.h>

#include "IWindow.h"
#include "MouseController.h"


class Window : public IWindow{

public:
	Window() = default;
	~Window();

	inline int getWidth() const override;
	inline int getHeight() const override;
	
	bool getFocused() const override;

	inline GLFWwindow* getWindow() const override;

	bool initialize();

	void setOpenGLVersion();
	void createWindow(int width, int height);
	void makeContextCurrentFrame();
	void setFrameBufferSizeCallback();

	void setWindowFocusAttrib();

	static void setFocusedOnWindow(GLFWwindow* window, int focused);
	void setWindowFocusCallback();

	void setCursorDisabled();
	void setCursorPositionCallback();

	int windowShouldClose();

	void swapBuffers();
	void destroyWindow();
	

private:
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	GLFWwindow* window{ nullptr };

	int _width;
	int _height;

    static bool _focused;
	
};