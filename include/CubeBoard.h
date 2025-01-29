#pragma once

#include "Cube.h"

#include "CubeRenderComponent.h"
#include "GrassTextureComponent.h"

class CubeBoard {
public:
	const static int CHUNK_SIZE = 16;

	//CubeBoard(Cube& cube, std::unique_ptr<BufferComponent> bufferComponent);
	CubeBoard(const glm::vec3& position, MvpComponent* mvpComponent);
	~CubeBoard();

	void init();
	void render();

	void destroyBuffers();

	glm::vec3 getPosition() const;

private:
	glm::vec3 position;
	
	std::unique_ptr<Cube> cube;
	//Cube& cube;

	std::unique_ptr<RenderComponent> cubeRender;
	std::unique_ptr<TextureComponent> cubeGrassTexture;
	std::unique_ptr<ShaderComponent> cubeShader;
	std::unique_ptr<BufferComponent> cubeBuffer;

	std::vector<glm::vec3> blocksPositions;

	GLuint vao;
	GLuint vbo;

};
