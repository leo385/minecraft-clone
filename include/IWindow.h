#pragma once

#include "GLFW/glfw3.h"
class IWindow {
public:
  virtual int getWidth() const = 0;
  virtual int getHeight() const = 0;

  virtual bool getFocused() const = 0;

  virtual GLFWwindow *getWindow() const = 0;
};
