#pragma once

#include "ShaderFile.h"

#include <string>


class Shader {

public:
	Shader() = default;
	~Shader() {}

	void use(const unsigned int& programID);
	void compileShaderFromFile(ShaderFile& shaderFile, unsigned int& programID);
	void deleteProgram(const unsigned int& programID);

	unsigned int getShaderID();

private:
	unsigned int vertex, fragment, programID;

	void deleteShader();

	void checkCompileErrors(unsigned int shader, std::string type);

};
