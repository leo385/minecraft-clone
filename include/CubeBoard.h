#pragma once

#include "Cube.h"

class CubeBoard {
public:
	CubeBoard(Cube& cube, std::unique_ptr<BufferComponent> bufferComponent);
	~CubeBoard();

	void init();
	void render();

private:
	Cube& cube;
	std::unique_ptr<BufferComponent> bufferComponent;

	std::vector<glm::vec3> blocksPositions;

	GLuint vao;
	GLuint vbo;
};
