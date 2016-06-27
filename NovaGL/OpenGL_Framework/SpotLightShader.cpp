#include "SpotLightShader.h"


SpotLightShader::SpotLightShader(const std::string& text) : Shader(text)
{
	
}


SpotLightShader::~SpotLightShader()
{
}

void SpotLightShader::ShaderUpdate()
{
	GLint matAmbientLoc = glGetUniformLocation(m_program, "ambient");

	glUniform3f(matAmbientLoc, light.diffuse.x, light.diffuse.y, light.diffuse.z);
}