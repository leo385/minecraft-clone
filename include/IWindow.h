#pragma once


class IWindow {

public:
	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;

	virtual GLFWwindow* getWindow() const = 0;
};