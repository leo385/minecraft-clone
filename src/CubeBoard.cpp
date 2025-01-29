#include "CubeBoard.h"


CubeBoard::CubeBoard(const glm::vec3& position, MvpComponent* mvpComponent) : position(position)
{
	vao = 0;
	vbo = 0;

	cubeRender = std::make_unique<CubeRenderComponent>();
	cubeGrassTexture = std::make_unique<GrassTextureComponent>();
	cubeShader = std::make_unique<ShaderComponent>();
	cubeBuffer = std::make_unique<BufferComponent>();

	cube = std::make_unique<Cube>(std::move(cubeRender), std::move(mvpComponent), std::move(cubeGrassTexture), std::move(cubeShader), std::move(cubeBuffer));

}

CubeBoard::~CubeBoard()
{
	cubeBuffer->deleteVAO(vao);
	cubeBuffer->deleteVBO(vbo);
}

void CubeBoard::destroyBuffers()
{
	if (vao != 0) {

		cubeBuffer->deleteVAO(vao);
		cubeBuffer->deleteVBO(vbo);

		cube->deleteBuffers();

		blocksPositions.clear();

		vao = 0;
		vbo = 0;
	}
}

glm::vec3 CubeBoard::getPosition() const
{
	return position;
}

#include <iostream>

void CubeBoard::init()
{
	if (blocksPositions.empty()) {

		//blocksPositions.resize(CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE);

		for (int x = 0; x < CHUNK_SIZE; x++) {
			for (int y = 0; y < CHUNK_SIZE; y++) {
				for (int z = 0; z < CHUNK_SIZE; z++) {

					blocksPositions.push_back(position + glm::vec3(x, 0, z));
				}
			}
		}

	}


	if (vao == 0) {

		cubeBuffer->generateVAO(vao);

		// Binding cube mesh with VAO, VBO, EBO
		cubeBuffer->bindVAO(vao);

		// VBO, EBO is inside cube init
		cube->init();

		cubeBuffer->unbindVAO();

		cubeBuffer->generateVBO(vbo);
		cubeBuffer->bindVBO(blocksPositions, vbo);
		glBufferData(GL_ARRAY_BUFFER, blocksPositions.size() * sizeof(glm::vec3), &blocksPositions[0], GL_DYNAMIC_DRAW);

		cubeBuffer->bindVAO(vao);

		cubeBuffer->setAttribPointer(3, 3, 3, 0);
		cubeBuffer->setAttribDivisor(3, 1); // Settings for instancing

		cubeBuffer->unbindVAO();
	}
	
}

void CubeBoard::render()
{
	if (vao != 0) {

		cube->sendToShader();

		cubeBuffer->bindVAO(vao);
		glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0, (GLsizei)blocksPositions.size());
		cubeBuffer->unbindVAO();
	}

}

