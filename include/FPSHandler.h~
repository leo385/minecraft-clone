#pragma once

#include "Cube.h"
#include "Camera.h"
#include "CameraMoving.h"
#include "CubeRenderComponent.h"
#include "GrassTextureComponent.h"

#include "MvpComponent.h"

#include "CubeBoard.h"

class Scene
{
private:

	std::unique_ptr<RenderComponent> cubeRender;
	std::unique_ptr<TextureComponent> cubeGrassTexture;
	std::unique_ptr<ShaderComponent> cubeShader;
	std::unique_ptr<BufferComponent> cubeBuffer;
	
	MvpComponent* mvpComponent;

	std::unique_ptr<Cube> cubeMesh;
	std::unique_ptr<CubeBoard> cubeBoard;

	std::unique_ptr<Camera> camera;
	CameraMoving cameraMoving;

	const IWindow& window;

	void setViewCamera();

public:
	explicit Scene(const IWindow&);
	~Scene();

	void init();
	void render();
	void handleInput();
};

