#include "Window.h"

#include <iostream>


Window::~Window()
{
}

bool Window::initialize()
{
	if (!window) {
		std::cerr << "Nie mo¿na stworzyæ okna GLFW\n";
		destroyWindow();
		return false;
	}

	return true;
}

void Window::setOpenGLVersion()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Window::createWindow(int width, int height)
{
	this->_width = width;
	this->_height = height;

	window = glfwCreateWindow(width, height, "Application", NULL, NULL);

}

void Window::makeContextCurrentFrame()
{
	glfwMakeContextCurrent(window);
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	int viewportwidth, viewportheight;
	float aspectratio = 16.0f / 9.0f;

	if (width / static_cast<float>(height) > aspectratio) {
		viewportwidth = static_cast<int>(height * aspectratio);
		viewportheight = height;
	}
	else {
		viewportwidth = width;
		viewportheight = static_cast<int>(width / aspectratio);
	}

	glViewport((width - viewportwidth) / 2, (height - viewportheight) / 2, viewportwidth, viewportheight);

	window = nullptr;
}

void Window::setFrameBufferSizeCallback()
{
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}


bool Window::_focused = false;

void Window::setFocusedOnWindow(GLFWwindow* window, int focused)
{
	_focused = focused;
}

void Window::setWindowFocusAttrib()
{
	_focused = glfwGetWindowAttrib(window, GLFW_FOCUSED);
}

void Window::setWindowFocusCallback()
{
	glfwSetWindowFocusCallback(window, setFocusedOnWindow);
}

void Window::setCursorDisabled()
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Window::setCursorPositionCallback()
{
	glfwSetCursorPosCallback(window, MouseController::mouse_callback);
}


int Window::windowShouldClose()
{
	return glfwWindowShouldClose(window);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(window);
}

void Window::destroyWindow()
{
	glfwDestroyWindow(window);
}

inline GLFWwindow* Window::getWindow() const
{
	return this->window;
}

inline int Window::getWidth() const
{
	return _width;
}

inline int Window::getHeight() const
{
	return _height;
}

bool Window::getFocused() const
{
	return _focused;
}





