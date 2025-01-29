#include "Cube.h"

#include "ShaderFile.h"


#include <iostream>


Cube::Cube(std::unique_ptr<RenderComponent> renderComponent, MvpComponent* mvpComponent, std::unique_ptr<TextureComponent> textureComponent,
       std::unique_ptr<ShaderComponent> shaderComponent, std::unique_ptr<BufferComponent> bufferComponent) 
        : renderComponent(std::move(renderComponent)), mvpComponent(std::move(mvpComponent)), textureComponent(std::move(textureComponent)),
          shaderComponent(std::move(shaderComponent)), bufferComponent(std::move(bufferComponent))
{
	// Przesuni�cie, �eby zapobiec nak�adaniu si� tekstur z kolorem obiektu.
	float offset = 0.0001f;

	vertices = {
	// Pozycje					   // Tekstury
	// Przednia �ciana
	-0.5f, -0.5f,  0.5f + offset,  1.0f, 1.0f,  // Lewy dolny
	 0.5f, -0.5f,  0.5f + offset,  0.0f, 1.0f,  // Prawy dolny
	 0.5f,  0.5f,  0.5f + offset,  0.0f, 0.0f,  // Prawy g�rny
	-0.5f,  0.5f,  0.5f + offset,  1.0f, 0.0f,  // Lewy g�rny

	// Tylna �ciana
	-0.5f, -0.5f, -0.5f - offset,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f - offset,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f - offset,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f - offset,  1.0f, 0.0f,

	// Lewa �ciana
	-0.5f - offset,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f - offset,  0.5f, -0.5f,  1.0f, 0.0f,
	-0.5f - offset, -0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f - offset, -0.5f,  0.5f,  0.0f, 1.0f,

	// Prawa �ciana
	 0.5f + offset,  0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f + offset,  0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f + offset, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f + offset, -0.5f,  0.5f,  0.0f, 1.0f,

	 // Dolna �ciana
	 -0.5f, -0.5f - offset, -0.5f,  0.0f, 1.0f,
	  0.5f, -0.5f - offset, -0.5f,  1.0f, 1.0f,
	  0.5f, -0.5f - offset,  0.5f,  1.0f, 0.0f,
	 -0.5f, -0.5f - offset,  0.5f,  0.0f, 0.0f,

	 // G�rna �ciana
	 -0.5f,  0.5f + offset, -0.5f,  0.0f, 1.0f,
	  0.5f,  0.5f + offset, -0.5f,  1.0f, 1.0f,
	  0.5f,  0.5f + offset,  0.5f,  1.0f, 0.0f,
	 -0.5f,  0.5f + offset,  0.5f,  0.0f, 0.0f,

	};

	indices = {
		// Przednia �ciana
		0, 1, 2,
		2, 3, 0,

		// Tylnia �ciana
		4, 5, 6,
		6, 7, 4,

		// Lewa �ciana
		8, 9, 10,
		10, 11, 8,

		// Prawa �ciana
		12, 13, 14,
		14, 15, 12,

		// Dolna �ciana
		16, 17, 18,
		18, 19, 16,

		// G�rna �ciana
		20, 21, 22,
		22, 23, 20
	};

	vbo = 0;
	ebo = 0;
}


void Cube::deleteBuffers()
{
	if (vbo != 0) {

		bufferComponent->deleteVBO(vbo);
		bufferComponent->deleteEBO(ebo);

		textureComponent->deleteTexture();

		vbo = 0;
		ebo = 0;
	}
}


void Cube::init()
{ 
	GLint vboSize = 0;

	if (vbo == 0) {

		// shader component
		shaderComponent->compileShaderFromFile("cubeVertexShader.vert", "cubeFragmentShader.frag");

		// generate buffers
		bufferComponent->generateVBO(vbo);
		bufferComponent->generateEBO(ebo);

		// bind buffer component
		bufferComponent->bindVBO(vertices, vbo);
		bufferComponent->bindEBO(indices, ebo);

		// vertex position
		bufferComponent->setAttribPointer(0, 3, 5, 0);

		// tex uv coords
		bufferComponent->setAttribPointer(1, 2, 5, 3);

		// unbind VBO, EBO
		bufferComponent->unbindVBO();

		textureComponent->applyTexture();

	}
}


void Cube::sendToShader()
{

		// shader component
		shaderComponent->useShaderProgram();

		mvpComponent->sendToShader(shaderComponent->getProgramID(), "mvp");

		textureComponent->sendToShader(shaderComponent->getProgramID());

		textureComponent->unbindTexture();
	
}