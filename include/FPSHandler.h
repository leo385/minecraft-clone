#pragma once

struct FPSHandler {

	FPSHandler() : currentTime{ 0.0f },
				   lastTime{ 0.0f },
				   fps{ 0.0f },
			       frameCount{ 0 } { }

	float currentTime;
	float lastTime;
	float fps;

	int frameCount;

	float calculateFps();
};