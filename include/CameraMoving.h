#pragma once

#include "Camera.h"

class CameraMoving
{
private:
	bool firstMouse;

	float lastX;
	float lastY;
	float yaw;
	float pitch;
	float sensitivity;

public:
	CameraMoving();
	void moveCameraWithMouse(Camera& camera);
};

