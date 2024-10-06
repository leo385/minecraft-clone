#pragma once

#include "Cube.h"
#include "Camera.h"
#include "CameraMoving.h"

class Scene
{
private:
	std::shared_ptr<RenderObject> object;
	std::unique_ptr<Camera> camera;
	CameraMoving cameraMoving;

	const IWindow& window;

	void setView();

public:
	Scene(const IWindow& window) : window(window) { }

	void init();
	void render();
	void handleInput();
};

