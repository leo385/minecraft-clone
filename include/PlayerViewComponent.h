#pragma once

#include "Camera.h"
#include "CameraMoving.h"

#include "CameraInterface.h"

#include <memory>

class PlayerViewComponent {
private:
	Camera* camera;
	CameraMoving cameraMoving;

	CameraInterface& cameraInterface;

	glm::vec3 position;

public:
	explicit PlayerViewComponent(CameraInterface& cameraInterface);
	~PlayerViewComponent();

	void init();
	void update(const IWindow& window);

	glm::vec3 getPos() const;
};