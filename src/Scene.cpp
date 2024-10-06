#include "Scene.h"

void Scene::init()
{
	camera = std::make_unique<Camera>();
	object = std::make_shared<Cube>(window);

	camera->init();
	object->init();
}

void Scene::render()
{
	object->render();



	/* Camera Free look */
	cameraMoving.moveCameraWithMouse(*camera);
	setView();
}

void Scene::handleInput()
{
	camera->handleInput(window);
}

void Scene::setView()
{
	object->getMVP().view = glm::lookAt(camera->getCameraPos(), camera->getCameraPos() + camera->getCameraFront(), camera->getCameraUp());
	object->getMVP().modelViewProjection = object->getMVP().projection * object->getMVP().view * object->getMVP().model;
}