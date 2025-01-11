#pragma once

#include "glm/glm.hpp"

class CameraInterface {
public:
	virtual ~CameraInterface() = default;

	virtual void setViewFromCamera(const glm::vec3& source, const glm::vec3& destination, const glm::vec3& UpDirection) = 0;
};