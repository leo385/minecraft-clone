#include "Cube.h"

#include "ShaderFile.h"


#include <iostream>

Cube::Cube(const IWindow& window) : _window(window){

	vertices = {
		-0.5f, -0.5f, -0.5f, // Wierzcho³ek 0
		 0.5f, -0.5f, -0.5f, // Wierzcho³ek 1
		 0.5f,  0.5f, -0.5f, // Wierzcho³ek 2
		-0.5f,  0.5f, -0.5f, // Wierzcho³ek 3
		-0.5f, -0.5f,  0.5f, // Wierzcho³ek 4
		 0.5f, -0.5f,  0.5f, // Wierzcho³ek 5
		 0.5f,  0.5f,  0.5f, // Wierzcho³ek 6
		-0.5f,  0.5f,  0.5f  // Wierzcho³ek 7
	};

	indices = {
		0, 1, 2, 2, 3, 0, // Przednia œciana
		1, 5, 6, 6, 2, 1, // Prawa œciana
		7, 6, 5, 5, 4, 7, // Tylna œciana
		4, 0, 3, 3, 7, 4, // Lewa œciana
		4, 5, 1, 1, 0, 4, // Dolna œciana
		3, 2, 6, 6, 7, 3  // Górna œciana
	};

}


Cube::~Cube()
{
	bufferObjectController.deleteBuffers();

	shader.deleteProgram();
}

void Cube::init()
{

	compileShaderCube();

	bufferObjectController.generateBuffers();
	
	bufferObjectController.bindVAO();
	
	bufferObjectController.bindVBO(vertices.size() * sizeof(float), &vertices[0]);
	bufferObjectController.bindEBO(indices.size() * sizeof(unsigned int), &indices[0]);
	bufferObjectController.enableVertexAttribPointer(0);

	bufferObjectController.unbindVAO();

	mvpInit();

	
	// Camera vec3
	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);


}

void Cube::render()
{
	shader.use();

	processInput();

	mvp.setMat4(shader.getShaderID(), "mvp");

	bufferObjectController.bindVAO();
	glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
	bufferObjectController.unbindVAO();

}

void Cube::compileShaderCube()
{
	ShaderFile shaderFile;

	shaderFile.openShaderFile("C:/Users/Leonard/Desktop/Projekty/Game/1/shader/cubeVertexShader.vert",
		"C:/Users/Leonard/Desktop/Projekty/Game/1/shader/cubeFragmentShader.frag");

	shader.compileShaderFromFile(shaderFile);
}

void Cube::mvpInit()
{
	mvp.init();

	mvp.model = glm::translate(mvp.model, glm::vec3(0.0f, 2.0f, -3.0f));
	mvp.view = glm::rotate(mvp.model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	mvp.projection = glm::perspective(glm::radians(45.0f), static_cast<float>(_window.getWidth()) / static_cast<float>(_window.getHeight()), 0.1f, 100.f);

	mvp.modelViewProjection = mvp.projection * mvp.view * mvp.model;
}

void Cube::processInput(){

	const float cameraSpeed = 0.05f;

	if (glfwGetKey(_window.getWindow(), GLFW_KEY_W) == GLFW_PRESS) {
		cameraPos += cameraSpeed * cameraFront;
	}
	if (glfwGetKey(_window.getWindow(), GLFW_KEY_S) == GLFW_PRESS) {
		cameraPos -= cameraSpeed * cameraFront;
	}
	if (glfwGetKey(_window.getWindow(), GLFW_KEY_A) == GLFW_PRESS) {
		cameraPos -= cameraSpeed * glm::normalize(glm::cross(cameraFront, cameraUp));
	}

	if (glfwGetKey(_window.getWindow(), GLFW_KEY_D) == GLFW_PRESS) {
		cameraPos += cameraSpeed * glm::normalize(glm::cross(cameraFront, cameraUp));
	}
	
	mvp.view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	mvp.modelViewProjection = mvp.projection * mvp.view * mvp.model;
}



