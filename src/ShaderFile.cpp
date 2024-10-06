#include "ShaderFile.h"

#include <fstream>
#include <sstream>
#include <iostream>

void ShaderFile::openShaderFile(const char* vertexPathFile, const char* fragmentPathFile)
{
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		vShaderFile.open(vertexPathFile);
		fShaderFile.open(fragmentPathFile);

		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		strVertexCode = vShaderStream.str();
		strFragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure& e) {
		std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ " << e.what() << "\n";
	}

	
}

std::string ShaderFile::getStrVertexCode()
{
		return strVertexCode;
}

std::string ShaderFile::getStrFragmentCode()
{
		return strFragmentCode;
}

