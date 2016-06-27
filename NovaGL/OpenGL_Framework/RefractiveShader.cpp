#include "RefractiveShader.h"

RefractiveShader::RefractiveShader() : Shader("RefractiveShader")
{
	type = sdr::Refractive;
	bindSettings = sdr::BIND_POS_NORMAL_TEX;
	ratio = 1.00 / 1.52;
}

RefractiveShader::~RefractiveShader()
{
}

void RefractiveShader::ShaderUpdate()
{
	GLint cameraPosLoc = glGetUniformLocation(m_program, "cameraPos");
	glm::vec3 camPos = ((Camera*)(Graphics::instance()->MainCamera))->transform->pos;
	SetVec3Unif(cameraPosLoc, camPos); 

	glActiveTexture(GL_TEXTURE0);
	GLuint cubemapTexLoc = glGetUniformLocation(m_program, "skybox");
	glUniform1i(cubemapTexLoc, 0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, Graphics::instance()->skyboxTex);

	GLuint ratioLoc = glGetUniformLocation(m_program, "ratio");
	glUniform1f(ratioLoc, ratio);
}