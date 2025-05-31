#pragma once

#include "types/gl_types.h"
#include "types/object_types.h"

#include <vector>

class RenderComponent;
class MvpComponent;
class TextureComponent;
class ShaderComponent;
class BufferComponent;

class Cube {
public:
  Cube() = default;
  Cube(component_types::UniqueComponent<RenderComponent> renderComponent,
       MvpComponent *mvpComponent,
       component_types::UniqueComponent<TextureComponent> textureComponent,
       component_types::UniqueComponent<ShaderComponent> shaderComponent,
       component_types::UniqueComponent<BufferComponent> bufferComponent);
  ~Cube();

  void init();
  void sendToShader();

private:
  component_types::UniqueComponent<RenderComponent> renderComponent;
  component_types::UniqueComponent<TextureComponent> textureComponent;
  component_types::UniqueComponent<ShaderComponent> shaderComponent;
  component_types::UniqueComponent<BufferComponent> bufferComponent;

  MvpComponent *mvpComponent;

  std::vector<gl::GLfloat> vertices{0};
  std::vector<gl::GLuint> indices{0};

  gl::GLuint vbo;
};
