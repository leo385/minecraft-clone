#pragma once

#include "RenderObject.h"
#include "Shader.h"
#include "BuffersObjectArray.h"

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.h"

class Cube : public RenderObject {

public:
	Cube() = default;
	Cube(const IWindow& window);
	~Cube();

	 void init() override;
	 void render() override;

private:
	void compileShaderCube();

	Shader shader;
	BuffersObjectArray bufferObject;

	std::vector<float> vertices{ 0 };
	std::vector<unsigned int> indices{ 0 };

	glm::mat4 model{ 0 }, view{ 0 }, projection{ 0 };
	glm::mat4 mvp{ 0 };

	glm::vec3 cameraPos{ 0 };
	glm::vec3 cameraFront{ 0 };
	glm::vec3 cameraUp{ 0 };


	const IWindow& _window;
	

};