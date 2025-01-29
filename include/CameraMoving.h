#pragma once

#include "Camera.h"

class CameraMoving
{
private:

	float yaw;
	float pitch;
	float sensitivity;

public:
	CameraMoving();
	void moveCameraWithMouse(const IWindow& window, Camera& camera);
};

