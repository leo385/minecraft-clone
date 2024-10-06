#include "Cube.h"

#include "ShaderFile.h"


#include <iostream>

Cube::Cube(const IWindow& window) : _window(window){

	// Przesuniêcie, ¿eby zapobiec nak³adaniu siê tekstur z kolorem obiektu.
	float offset = 0.0001f;

	vertices = {
		// Pozycje          // Tekstury
	// Przednia œciana
	-0.5f, -0.5f,  0.5f + offset,  1.0f, 1.0f,  // Lewy dolny
	 0.5f, -0.5f,  0.5f + offset,  0.0f, 1.0f,  // Prawy dolny
	 0.5f,  0.5f,  0.5f + offset,  0.0f, 0.0f,  // Prawy górny
	-0.5f,  0.5f,  0.5f + offset,  1.0f, 0.0f,  // Lewy górny

	// Tylna œciana
	-0.5f, -0.5f, -0.5f - offset,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f - offset,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f - offset,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f - offset,  1.0f, 0.0f,

	// Lewa œciana
	-0.5f - offset,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f - offset,  0.5f, -0.5f,  1.0f, 0.0f,
	-0.5f - offset, -0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f - offset, -0.5f,  0.5f,  0.0f, 1.0f,

	// Prawa œciana
	 0.5f + offset,  0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f + offset,  0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f + offset, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f + offset, -0.5f,  0.5f,  0.0f, 1.0f,

	 // Dolna œciana
	 -0.5f, -0.5f - offset, -0.5f,  0.0f, 1.0f,
	  0.5f, -0.5f - offset, -0.5f,  1.0f, 1.0f,
	  0.5f, -0.5f - offset,  0.5f,  1.0f, 0.0f,
	 -0.5f, -0.5f - offset,  0.5f,  0.0f, 0.0f,

	 // Górna œciana
	 -0.5f,  0.5f + offset, -0.5f,  0.0f, 1.0f,
	  0.5f,  0.5f + offset, -0.5f,  1.0f, 1.0f,
	  0.5f,  0.5f + offset,  0.5f,  1.0f, 0.0f,
	 -0.5f,  0.5f + offset,  0.5f,  0.0f, 0.0f,

	};

	indices = {
		// Przednia œciana
		0, 1, 2,
		2, 3, 0,

		// Tylnia œciana
		4, 5, 6,
		6, 7, 4,

		// Lewa œciana
		8, 9, 10,
		10, 11, 8,

		// Prawa œciana
		12, 13, 14,
		14, 15, 12,

		// Dolna œciana
		16, 17, 18,
		18, 19, 16,

		// Górna œciana
		20, 21, 22,
		22, 23, 20
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

	GLuint textureID[3];

	// init front texture
	texture.init(&textureID[0], GL_TEXTURE0);
	texture.setTextureParameter(GL_CLAMP_TO_BORDER, GL_NEAREST, GL_LINEAR_MIPMAP_LINEAR);
	texture.loadTextureIntoGL("assets/cube/cube_grass_normal.png");

	// init top texture
	texture.init(&textureID[1], GL_TEXTURE1);
	texture.setTextureParameter(GL_CLAMP_TO_BORDER, GL_NEAREST, GL_LINEAR_MIPMAP_LINEAR);
	texture.loadTextureIntoGL("assets/cube/cube_grass_top.png");

	// init bottom texture
	texture.init(&textureID[2], GL_TEXTURE2);
	texture.setTextureParameter(GL_CLAMP_TO_BORDER, GL_NEAREST, GL_LINEAR_MIPMAP_LINEAR);
	texture.loadTextureIntoGL("assets/cube/cube_grass_bottom.png");

	bufferObjectController.bindVAO();
	
	bufferObjectController.bindVBO(vertices.size() * sizeof(float), &vertices[0]);
	bufferObjectController.bindEBO(indices.size() * sizeof(unsigned int), &indices[0]);

	// vertices
	bufferObjectController.setVertexAttribPointer(0, 3, 5, 0);
	bufferObjectController.enableVertexAttribPointer(0);

	// tex uv coords
	bufferObjectController.setVertexAttribPointer(1, 2, 5, 3);
	bufferObjectController.enableVertexAttribPointer(1);

	bufferObjectController.unbindVBO();
	bufferObjectController.unbindVAO();

	mvp.init();

	mvp.model = glm::translate(mvp.model, glm::vec3(0.0f, 0.0f, -3.0f));
	mvp.view = glm::rotate(mvp.model, glm::radians(-55.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	mvp.projection = glm::perspective(glm::radians(60.0f), static_cast<float>(_window.getWidth()) / static_cast<float>(_window.getHeight()), 0.1f, 100.f);

	mvp.modelViewProjection = mvp.projection * mvp.view * mvp.model;

}

void Cube::render()
{
	shader.use();

	texture.sendTextureToShader(shader.getShaderID(), "texture0", 0);
	texture.sendTextureToShader(shader.getShaderID(), "texture1", 1);
	texture.sendTextureToShader(shader.getShaderID(), "texture2", 2);

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


MVP& Cube::getMVP()
{
	return mvp;
}