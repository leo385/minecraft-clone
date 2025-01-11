#include "PlayerViewComponent.h"

PlayerViewComponent::PlayerViewComponent(CameraInterface& cameraInterface) : 
	cameraInterface(cameraInterface), position(0)
{
	camera = new Camera();
}

PlayerViewComponent::~PlayerViewComponent()
{
	if (camera)
		delete camera;
}

void PlayerViewComponent::init()
{
	camera->init();
}

void PlayerViewComponent::update(const IWindow& window)
{
	camera->handleInput(window);
	cameraMoving.moveCameraWithMouse(window, *camera);

	cameraInterface.setViewFromCamera(camera->getCameraPos(), camera->getCameraPos() + camera->getCameraFront(), camera->getCameraUp());

	position = camera->getCameraPos();

}

glm::vec3 PlayerViewComponent::getPos() const
{
	return position;
}
