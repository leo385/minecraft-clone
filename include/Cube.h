#pragma once

#include "RenderObject.h"
#include "Shader.h"
#include "BuffersObjectController.h"
#include "MVP.h"
#include "Camera.h"
#include "Texture.h"

#include <vector>
#include <memory>


class Cube : public RenderObject {

public:
	Cube() = default;
	Cube(const IWindow& window);
	~Cube();

	 void init() override;
	 void render() override;

	 MVP& getMVP() override;

private:
	void compileShaderCube();

	Shader shader;
	BuffersObjectController bufferObjectController;
	MVP mvp;
	
	Texture texture;

	std::vector<GLfloat> vertices{ 0 };
	std::vector<GLuint> indices{ 0 };

	const IWindow& _window;
	

};