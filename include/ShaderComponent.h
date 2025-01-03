#pragma once

#include "ShaderFile.h"
#include "Shader.h"

class ShaderComponent{
  private:
    Shader shader;

    unsigned int programID;

  public:
    ShaderComponent() = default;
    ~ShaderComponent();

    void compileShaderFromFile(const char* vertexFile, const char* fragmentFile);
    void useShaderProgram();
	
    unsigned int& getProgramID();
};
