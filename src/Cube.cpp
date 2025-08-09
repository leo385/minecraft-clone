#include "Cube.h"

// Components
#include "BufferComponent.h"
#include "MvpComponent.h"
#include "RenderComponent.h"
#include "ShaderComponent.h"
#include "TextureComponent.h"

#include "CubeMeshJsonParser.h"

Cube::Cube(component_types::UniqueComponent<RenderComponent> renderComponent,
           MvpComponent *mvpComponent,
           component_types::UniqueComponent<TextureComponent> textureComponent,
           component_types::UniqueComponent<ShaderComponent> shaderComponent,
           component_types::UniqueComponent<BufferComponent> bufferComponent)
    : renderComponent(std::move(renderComponent)),
      mvpComponent(std::move(mvpComponent)),
      textureComponent(std::move(textureComponent)),
      shaderComponent(std::move(shaderComponent)),
      bufferComponent(std::move(bufferComponent)) {

  std::unique_ptr<CubeMeshJsonParser> cubeJsonParser = std::make_unique<CubeMeshJsonParser>();
  vertices = cubeJsonParser->getVerticesFromVectorOfWalls(); // 162M used memory

  indices = {// Przednia œciana
             0, 1, 2, 2, 3, 0,

             // Tylnia œciana
             4, 5, 6, 6, 7, 4,

             // Lewa œciana
             8, 9, 10, 10, 11, 8,

             // Prawa œciana
             12, 13, 14, 14, 15, 12,

             // Dolna œciana
             16, 17, 18, 18, 19, 16,

             // Górna œciana
             20, 21, 22, 22, 23, 20};
}

Cube::~Cube() {
  bufferComponent->deleteVBO(vbo);
  bufferComponent->deleteEBO();
}

void Cube::init() {
  // shader component
  shaderComponent->compileShaderFromFile("cubeVertexShader.vert",
                                         "cubeFragmentShader.frag");

  // generate buffers
  bufferComponent->generateVBO(vbo);
  bufferComponent->generateEBO();

  // bind buffer component
  bufferComponent->bindVBO(vertices, vbo);
  bufferComponent->bindEBO(indices);

  // vertex position
  bufferComponent->setAttribPointer(0, 3, 5, 0);

  // tex uv coords
  bufferComponent->setAttribPointer(1, 2, 5, 3);

  // unbind VBO, EBO
  bufferComponent->unbindVBO();

  textureComponent->applyTexture();

  // set model for mvp
  mvpComponent->setModel(glm::vec3(0.0f, 0.0f, -3.0f));
}

void Cube::sendToShader() {
  // shader component
  shaderComponent->useShaderProgram();

  mvpComponent->sendToShader(shaderComponent->getProgramID(), "mvp");

  textureComponent->sendToShader(shaderComponent->getProgramID());
}
