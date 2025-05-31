#pragma once

#include <GL/glew.h>
#include <vector>

class RenderComponent {
public:
  virtual ~RenderComponent() = default;
  virtual void render(const std::vector<GLuint> &indices) = 0;
};
