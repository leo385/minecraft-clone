#pragma once

#include "FPSHandler.h"
#include "IWindow.h"

class GuiHandler {
public:
  GuiHandler() = default;
  ~GuiHandler();

  void init(const IWindow &window);
  void render();

private:
  FPSHandler fpsHandler;
};
