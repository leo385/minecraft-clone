#pragma once

#include "ShaderFile.h"

#include <string>


class Shader {

public:
	Shader() = default;
	~Shader() {}

	void use();
	void compileShaderFromFile(ShaderFile& shaderFile);
	void deleteProgram();

	unsigned int getShaderID();

private:
	unsigned int vertex, fragment, programID;

	void deleteShader();

	void checkCompileErrors(unsigned int shader, std::string type);

};