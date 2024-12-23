#pragma once

#include "RenderComponent.h"
#include "TextureComponent.h"
#include "ShaderComponent.h"
#include "MvpComponent.h"
#include "BufferComponent.h"


#include <algorithm>
#include <vector>
#include <memory>


class Cube{

public:
	Cube() = default;
	Cube(std::unique_ptr<RenderComponent> renderComponent, MvpComponent* mvpComponent, std::unique_ptr<TextureComponent> textureComponent,
        std::unique_ptr<ShaderComponent> shaderComponent, std::unique_ptr<BufferComponent> bufferComponent);
	~Cube() = default;

	void init();
	void render();


private:
	std::unique_ptr<RenderComponent> renderComponent;
	std::unique_ptr<TextureComponent> textureComponent;
	std::unique_ptr<ShaderComponent> shaderComponent;
	std::unique_ptr<BufferComponent> bufferComponent;

	MvpComponent* mvpComponent;

	std::vector<GLfloat> vertices{ 0 };
	std::vector<GLuint> indices{ 0 };
	
};
