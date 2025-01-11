#pragma once

class IWindow {
public:
	virtual ~IWindow() = default;

	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;

	virtual bool getFocused() const = 0;

	virtual GLFWwindow* getWindow() const = 0;
};
