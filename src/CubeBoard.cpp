#include "CubeBoard.h"

CubeBoard::CubeBoard(Cube& cube, std::unique_ptr<BufferComponent> bufferComponent) 
	: cube(cube), bufferComponent(std::move(bufferComponent))
{

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			for (int z = 0; z < 10; z++) {

				blocksPositions.push_back(glm::vec3(x, 0, z));
			}
		}
	}

}

CubeBoard::~CubeBoard()
{
	bufferComponent->deleteVAO(vao);
	bufferComponent->deleteVBO(vbo);
}

void CubeBoard::init()
{

	bufferComponent->generateVAO(vao);

	// Binding cube mesh with VAO, VBO, EBO
	bufferComponent->bindVAO(vao);

	// VBO, EBO is inside cube init
	cube.init();

	bufferComponent->unbindVAO();

	bufferComponent->generateVBO(vbo);
	bufferComponent->bindVBO(blocksPositions, vbo);
	glBufferData(GL_ARRAY_BUFFER, blocksPositions.size() * sizeof(glm::vec3), &blocksPositions[0], GL_STATIC_DRAW);

	bufferComponent->bindVAO(vao);

	bufferComponent->setAttribPointer(3, 3, 3, 0);
	bufferComponent->setAttribDivisor(3, 1); // Settings for instancing

	bufferComponent->unbindVAO();
	
}

void CubeBoard::render()
{
	cube.sendToShader();

	bufferComponent->bindVAO(vao);
	glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0, (GLsizei)blocksPositions.size());
	bufferComponent->unbindVAO();
}
