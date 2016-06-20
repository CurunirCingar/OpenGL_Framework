#include "SkyboxTransform.h"


SkyboxTransform::SkyboxTransform() : Transform()
{
}


SkyboxTransform::~SkyboxTransform()
{
}

void SkyboxTransform::Update()
{
	glm::mat4 view = glm::mat4(glm::mat3(*cameraViewMatrix));

	glm::mat4 projection;
	GLfloat aspect = ((float)Graphics::instance()->width) / ((float)Graphics::instance()->height);
	projection = glm::perspective(45.0f, aspect, 0.5f, 500.0f);

	GLint viewLoc = glGetUniformLocation(m_program, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	GLint projectionLoc = glGetUniformLocation(m_program, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
}