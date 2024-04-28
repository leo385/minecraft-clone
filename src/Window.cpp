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
	glViewport(0, 0, width, height);
	std::cout << window << "\n";
}

void Window::setFrameBufferSizeCallback()
{
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
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

int Window::getWidth() const
{
	return _width;
}

int Window::getHeight() const
{
	return _height;
}






