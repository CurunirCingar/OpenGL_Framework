#include "StandardShader.h"

StandardShader::StandardShader() : Shader("StandardShader")
{
	type = sdr::Standard;
	shininess = 32;
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

	GLint matShineLoc =		glGetUniformLocation(m_program, "material.shininess");
	glUniform1f(matShineLoc, shininess);

	
}

