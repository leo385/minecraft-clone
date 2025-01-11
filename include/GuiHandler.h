#pragma once

#include "Window.h"
#include "FPSHandler.h"

#include "Player.h"

class GuiHandler {
public:
	GuiHandler() = default;
	~GuiHandler();

	void init(const IWindow& window);
	void render();
	void getInfo(Player *_player);

private:
	FPSHandler fpsHandler;
	Player* player = nullptr;
};