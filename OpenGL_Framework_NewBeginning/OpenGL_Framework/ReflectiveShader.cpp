#include "ReflectiveShader.h"


ReflectiveShader::ReflectiveShader() : Shader("ReflectiveShader")
{
	type = sdr::Reflective;
}

ReflectiveShader::~ReflectiveShader()
{
}

void ReflectiveShader::ShaderUpdate()
{
	GLint cameraPosLoc = glGetUniformLocation(m_program, "cameraPos");
	SetVec3Unif(cameraPosLoc, ((Camera*)(Graphics::instance()->MainCamera))->transform->pos);

	glActiveTexture(GL_TEXTURE0);
	GLuint cubemapTexLoc = glGetUniformLocation(m_program, "skybox");
	GLuint* texLoc = (GLuint*)(Graphics::instance()->Skybox);
	glUniform1i(cubemapTexLoc, 0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, *texLoc);
}