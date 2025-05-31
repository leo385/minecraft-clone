#pragma once

#include "RenderComponent.h"

class CubeRenderComponent : public RenderComponent {
public:
  ~CubeRenderComponent() = default;
  void render(const std::vector<GLuint> &indices) override;
};
