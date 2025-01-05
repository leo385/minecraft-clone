#pragma once

#include "Window.h"
#include "FPSHandler.h"

class GuiHandler {
public:
	GuiHandler() = default;
	~GuiHandler();

	void init(const IWindow& window);
	void render();

private:
	FPSHandler fpsHandler;
};