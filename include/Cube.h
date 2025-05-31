#pragma once

#include "BufferComponent.h"
#include "MvpComponent.h"
#include "RenderComponent.h"
#include "ShaderComponent.h"
#include "TextureComponent.h"

#include <memory>
#include <vector>

class Cube {

public:
  Cube() = default;
  Cube(std::unique_ptr<RenderComponent> renderComponent,
       MvpComponent *mvpComponent,
       std::unique_ptr<TextureComponent> textureComponent,
       std::unique_ptr<ShaderComponent> shaderComponent,
       std::unique_ptr<BufferComponent> bufferComponent);
  ~Cube();

  void init();
  void sendToShader();

private:
  std::unique_ptr<RenderComponent> renderComponent;
  std::unique_ptr<TextureComponent> textureComponent;
  std::unique_ptr<ShaderComponent> shaderComponent;
  std::unique_ptr<BufferComponent> bufferComponent;

  MvpComponent *mvpComponent;

  std::vector<GLfloat> vertices{0};
  std::vector<GLuint> indices{0};

  GLuint vbo;
};
