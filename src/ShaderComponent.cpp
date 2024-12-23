#include "ShaderComponent.h"

#include <filesystem>

using fs = std::filesystem::path;

ShaderComponent::~ShaderComponent(){
  
    shader.deleteProgram(programID);
}

void ShaderComponent::compileShaderFromFile(const char* vertexFile, const char* fragmentFile){
  
    ShaderFile shaderFile;

    fs vertexFilePath = SHADERS_PATH / fs(vertexFile);
    fs fragmentFilePath = SHADERS_PATH / fs(fragmentFile);

    shaderFile.openShaderFile(vertexFilePath.string().c_str(), fragmentFilePath.string().c_str());

    shader.compileShaderFromFile(shaderFile, programID);
}

void ShaderComponent::useShaderProgram(){
    
    shader.use(programID);
}


unsigned int& ShaderComponent::getProgramID(){
	return programID;
}
