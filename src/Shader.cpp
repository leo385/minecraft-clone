#include "Shader.h"

#include <ShaderCode.h>
#include "../ShaderFile.h"
#include "Shader.h"

Shader::Shader() {


}

void Shader::compileShader() {

	
	ShaderFile shaderFile;
	ShaderCode shaderCode;

	std::string strVertexCode = shaderFile.getStrVertexCode();
	std::string strFragmentCode = shaderFile.getStrFragmentCode();

	shaderCode.vShaderCode = strVertexCode.c_str();
	shaderCode.fShaderCode = strFragmentCode.c_str();


	
}

void Shader::deleteShader() {


}

void Shader::checkCompileErrors(unsigned int shader, std::string type)
{

}
