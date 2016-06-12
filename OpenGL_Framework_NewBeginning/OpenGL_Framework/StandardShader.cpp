#include "StandardShader.h"

StandardShader::StandardShader(const std::string& text) : Shader(text)
{
	type = ShaderTypes::Standard;
}

StandardShader::~StandardShader()
{
}

void StandardShader::ShaderUpdate()
{
	GLint viewPosLoc = glGetUniformLocation(m_program, "viewPos");
	SetVec3Unif(viewPosLoc, ((Camera*)(Graphics::instance()->MainCamera))->transform->pos);
	
	for each (void* lightSourcePtr in Graphics::instance()->lightSources)
	{
		((LightSource*)lightSourcePtr)->SetStandardShader(m_program);
	}

	/*GLint matAmbientLoc =	glGetUniformLocation(m_program, "material.ambient");
	GLint matDiffuseLoc =	glGetUniformLocation(m_program, "material.diffuse");
	GLint matSpecularLoc =	glGetUniformLocation(m_program, "material.specular");*/
	GLint matShineLoc =		glGetUniformLocation(m_program, "material.shininess");
	/*glUniform3f(matAmbientLoc, 0.1f, 0.1f, 0.1f);
	glUniform3f(matDiffuseLoc, 0.0f, 0.5f, 0.31f);
	glUniform3f(matSpecularLoc, 0.5f, 0.5f, 0.5f);*/
	glUniform1f(matShineLoc, 32);

	
}

