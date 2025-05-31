#pragma once

#include "BufferComponent.h"
#include "Cube.h"

#include <glm/glm.hpp>

class CubeBoard {
public:
  CubeBoard(Cube &cube,
            component_types::UniqueComponent<BufferComponent> bufferComponent);
  ~CubeBoard();

  void init();
  void render();

private:
  Cube &cube;
  component_types::UniqueComponent<BufferComponent> bufferComponent;

  std::vector<glm::vec3> blocksPositions;

  gl::GLuint vao;
  gl::GLuint vbo;
};
