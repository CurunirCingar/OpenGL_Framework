#include "ReflectiveShader.h"


ReflectiveShader::ReflectiveShader() : Shader("ReflectiveShader")
{
	type = sdr::Reflective;
	bindSettings = sdr::BIND_POS_NORMAL_TEX;
}

ReflectiveShader::~ReflectiveShader()
{
}

void ReflectiveShader::ShaderUpdate()
{
	GLint cameraPosLoc = glGetUniformLocation(m_program, "cameraPos");
	glm::vec3 camPos = ((Camera*)(Graphics::instance()->MainCamera))->transform->pos;
	SetVec3Unif(cameraPosLoc, camPos);

	glActiveTexture(GL_TEXTURE0);
	GLuint cubemapTexLoc = glGetUniformLocation(m_program, "skybox");
	glUniform1i(cubemapTexLoc, 0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, Graphics::instance()->skyboxTex);
}