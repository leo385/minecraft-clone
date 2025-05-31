#pragma once
#include <GL/glew.h>

#include "Camera.h"
#include "CameraMoving.h"
#include "Cube.h"

#include "MvpComponent.h"

#include "object_types.h"

// forward declarations
class CubeBoard;

using namespace component_types;

class Scene {
private:
  UniqueComponent<RenderComponent> cubeRender;
  UniqueComponent<TextureComponent> cubeGrassTexture;
  UniqueComponent<ShaderComponent> cubeShader;
  UniqueComponent<BufferComponent> cubeBuffer;

  MvpComponent *mvpComponent;

  std::unique_ptr<Cube> cubeMesh;
  std::unique_ptr<CubeBoard> cubeBoard;

  std::unique_ptr<Camera> camera;
  CameraMoving cameraMoving;

  const IWindow &window;

  void setViewCamera();

public:
  explicit Scene(const IWindow &);
  ~Scene();

  void init();
  void render();
  void handleInput();
};
