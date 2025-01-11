#include "ShaderCode.h"

#include "Shader.h"

#include <GL/glew.h>

#include <iostream>


void Shader::compileShaderFromFile(ShaderFile& shaderFile, unsigned int& programID) {

	ShaderCode shaderCode;

	std::string strVertexCode = shaderFile.getStrVertexCode();
	std::string strFragmentCode = shaderFile.getStrFragmentCode();

	shaderCode.vShaderCode = strVertexCode.c_str();
	shaderCode.fShaderCode = strFragmentCode.c_str();

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &shaderCode.vShaderCode, NULL);
	glCompileShader(vertex);
	checkCompileErrors(vertex, "SHADER");

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &shaderCode.fShaderCode, NULL);
	glCompileShader(fragment);
	checkCompileErrors(fragment, "SHADER");

	programID = glCreateProgram();
	glAttachShader(programID, vertex);
	glAttachShader(programID, fragment);
	glLinkProgram(programID);
	checkCompileErrors(programID, "PROGRAM");

	deleteShader();
	
}


void Shader::deleteShader() {

	glDeleteShader(vertex);
	glDeleteShader(fragment);

}

void Shader::use(const unsigned int& programID)
{
	glUseProgram(programID);
}

void Shader::deleteProgram(const unsigned int& programID)
{
	glDeleteProgram(programID);
}

unsigned int Shader::getShaderID()
{
	return programID;
}

void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
	char infoLog[1024];
	int success = 0;

	if (type != "PROGRAM") {
		
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << infoLog << "\n";
		}
		
	}
	else {
		
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cerr << "ERROR:PROGRAM_COMPILING_ERROR of type: " << type << infoLog << "\n";
		}

	}
}
