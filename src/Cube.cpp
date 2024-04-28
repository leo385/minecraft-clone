#include "Cube.h"

#include "ShaderFile.h"


#include <iostream>

Cube::Cube(const IWindow& window) : _window(window){

	vertices = {
		// Przód
		-0.5, -0.5, 0.5,  0.5, -0.5, 0.5,  0.5, 0.5, 0.5,
		0.5, 0.5, 0.5,  -0.5, 0.5, 0.5,  -0.5, -0.5, 0.5,
		// Ty³
		-0.5, -0.5, -0.5,  -0.5, 0.5, -0.5,  0.5, 0.5, -0.5,
		0.5, 0.5, -0.5,  0.5, -0.5, -0.5,  -0.5, -0.5, -0.5,
		// Lewo
		-0.5, 0.5, 0.5,  -0.5, 0.5, -0.5,  -0.5, -0.5, -0.5,
		-0.5, -0.5, -0.5,  -0.5, -0.5, 0.5,  -0.5, 0.5, 0.5,
		// Prawo
		0.5, 0.5, 0.5,  0.5, -0.5, 0.5,  0.5, -0.5, -0.5,
		0.5, -0.5, -0.5,  0.5, 0.5, -0.5,  0.5, 0.5, 0.5,
		// Dó³
		-0.5, -0.5, -0.5,  0.5, -0.5, -0.5,  0.5, -0.5, 0.5,
		0.5, -0.5, 0.5,  -0.5, -0.5, 0.5,  -0.5, -0.5, -0.5,
		// Góra
		-0.5, 0.5, -0.5,  -0.5, 0.5, 0.5,  0.5, 0.5, 0.5,
		0.5, 0.5, 0.5,  0.5, 0.5, -0.5,  -0.5, 0.5, -0.5,
	};

	indices = {
		// Front face
		0, 1, 2, 2, 3, 0,
		// Top face
		1, 5, 6, 6, 2, 1,
		// Back face
		7, 6, 5, 5, 4, 7,
		// Bottom face
		4, 0, 3, 3, 7, 4,
		// Left face
		4, 5, 1, 1, 0, 4,
		// Right face
		3, 2, 6, 6, 7, 3
	};

}


Cube::~Cube()
{
	glDeleteVertexArrays(1, &bufferObject.VAO);
	glDeleteBuffers(1, &bufferObject.VBO);
	glDeleteBuffers(1, &bufferObject.EBO);

	shader.deleteProgram();
}

void Cube::init()
{

	compileShaderCube();

	glGenVertexArrays(1, &bufferObject.VAO);
	glGenBuffers(1, &bufferObject.VBO);
	glGenBuffers(1, &bufferObject.EBO);
	
	glBindVertexArray(bufferObject.VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, bufferObject.VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferObject.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	glBindVertexArray(0);

	

	// MVP stuff doing
	/*model = glm::mat4(1.0f);
	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);
	mvp = glm::mat4(1.0f);

	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -1.0f));
	view = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	projection = glm::perspective(glm::radians(45.0f), static_cast<float>(window.getWindowWidth()) / static_cast<float>(window.getWindowHeight()), 0.1f, 100.f);

	mvp = projection * view * model;*/



	std::cout << _window.getWidth() << "\n";
	std::cout << _window.getHeight() << "\n";


}

void Cube::render()
{
	shader.use();

	glBindVertexArray(bufferObject.VAO);
	glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

}

void Cube::compileShaderCube()
{
	ShaderFile shaderFile;

	shaderFile.openShaderFile("C:/Users/Leonard/Desktop/Projekty/Game/1/shader/cubeVertexShader.vert",
		"C:/Users/Leonard/Desktop/Projekty/Game/1/shader/cubeFragmentShader.frag");

	shader.compileShaderFromFile(shaderFile);
}

