#include "Scene.h"

#include <iostream>

Scene::~Scene()
{
	if (!mvpComponent)
		delete mvpComponent;
	
}

void Scene::init()
{
	camera = std::make_unique<Camera>();
	camera->init();
  
	cubeRender = std::make_unique<CubeRenderComponent>();
	cubeGrassTexture = std::make_unique<GrassTextureComponent>();
	cubeShader = std::make_unique<ShaderComponent>();
	cubeBuffer = std::make_unique<BufferComponent>();

	
	mvpComponent = new MvpComponent();

	// set global view rotate mvp
	mvpComponent->setViewRotate(-55.0f, glm::vec3(0.0f, 0.0f, 0.0f));

	// set global projection mvp
	mvpComponent->setProjection(static_cast<float>(window.getWidth()) / static_cast<float>(window.getHeight()));

	setViewCamera();
	
	cubeMesh = std::make_shared<Cube>(std::move(cubeRender), std::move(mvpComponent), std::move(cubeGrassTexture), std::move(cubeShader), std::move(cubeBuffer));

	cubeMesh->init();

}

void Scene::render()
{
	cubeMesh->render();

	/* Camera Free look */
	cameraMoving.moveCameraWithMouse(window, *camera);
  	//cameraMoving.moveCameraWithArrows(window, *camera);

	setViewCamera();
}

void Scene::handleInput()
{
	camera->handleInput(window);
}

void Scene::setViewCamera()
{
	mvpComponent->setViewFromCamera(camera->getCameraPos(), camera->getCameraPos() + camera->getCameraFront(), camera->getCameraUp());
}
