#pragma once

#include "RenderObject.h"
#include "Shader.h"
#include "BuffersObjectController.h"
#include "MVP.h"
#include "Window.h"

#include <vector>


class Cube : public RenderObject {

public:
	Cube() = default;
	Cube(const IWindow& window);
	~Cube();

	 void init() override;
	 void render() override;

private:
	void compileShaderCube();
	void processInput();
	
	void mvpInit();

	Shader shader;
	BuffersObjectController bufferObjectController;
	MVP mvp;

	std::vector<GLfloat> vertices{ 0 };
	std::vector<GLuint> indices{ 0 };

	glm::vec3 cameraPos{ 0 };
	glm::vec3 cameraFront{ 0 };
	glm::vec3 cameraUp{ 0 };


	const IWindow& _window;
	

};