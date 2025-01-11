#include "Scene.h"

#include <iostream>


Scene::Scene(const IWindow& window) : window(window){

	camera = std::make_unique<Camera>();
	mvpComponent = new MvpComponent();

	cubeRender = std::make_unique<CubeRenderComponent>();
	cubeGrassTexture = std::make_unique<GrassTextureComponent>();
	cubeShader = std::make_unique<ShaderComponent>();
	cubeBuffer = std::make_unique<BufferComponent>();

}

Scene::~Scene()
{
	if (!mvpComponent)
		delete mvpComponent;
	
}

void Scene::init()
{
	
	camera->init();

	// set global view rotate mvp
	mvpComponent->setViewRotate(-55.0f, glm::vec3(0.0f, 0.0f, 0.0f));

	// set global projection mvp
	mvpComponent->setProjection(static_cast<float>(window.getWidth()) / static_cast<float>(window.getHeight()));

	setViewCamera();
	
	cubeMesh = std::make_unique<Cube>(std::move(cubeRender), std::move(mvpComponent), std::move(cubeGrassTexture), std::move(cubeShader), std::move(cubeBuffer));
	cubeBoard = std::make_unique<CubeBoard>(*cubeMesh, std::move(cubeBuffer));

	cubeBoard->init();

}

void Scene::render()
{
	cubeBoard->render();

	/* Camera Free look */
	cameraMoving.moveCameraWithMouse(window, *camera);
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
