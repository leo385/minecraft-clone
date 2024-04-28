#pragma once

#include <string>


class ShaderFile {

public:
	ShaderFile() = default;

	~ShaderFile(){}
	
	void openShaderFile(const char* vertexPathFile, const char* fragmentPathFile);

	std::string getStrVertexCode();
	std::string getStrFragmentCode();


private:
	std::string strVertexCode;
	std::string strFragmentCode;


};