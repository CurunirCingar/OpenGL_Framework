#include "LightSources.h"

PointLightSource::PointLightSource(Structs::Transform* transform)
{
	type = lightSrc::Point;

	position = &transform->pos;
	direction = &transform->rot;

	ambient = glm::vec3(0.1, 0.1, 0.1);
	diffuse = glm::vec3(0.7, 0.7, 0.7);
	specular = glm::vec3(1, 1, 1);

	constant = 1.0f;
	linear = 0.09;
	quadratic = 0.032;
}

PointLightSource::~PointLightSource()
{
}

void PointLightSource::SetLightShader(GLuint shader)
{
	GLint matAmbientLoc = glGetUniformLocation(shader, "ambient");

	glUniform4f(matAmbientLoc, diffuse.x, diffuse.y, diffuse.z, 1);
}

void PointLightSource::SetStandardShader(GLuint shader)
{
	GLint lightPosLoc =				glGetUniformLocation(shader, "pointLights[0].position");
	SetVec3Unif(lightPosLoc, *position);

	GLint lightAmbientLoc =			glGetUniformLocation(shader, "pointLights[0].ambient");
	GLint lightDiffuseLoc =			glGetUniformLocation(shader, "pointLights[0].diffuse");
	GLint lightSpecularLoc =		glGetUniformLocation(shader, "pointLights[0].specular");
	SetVec3Unif(lightAmbientLoc, ambient);
	SetVec3Unif(lightDiffuseLoc, diffuse);
	SetVec3Unif(lightSpecularLoc, specular);

	GLint lightConstantLoc =		glGetUniformLocation(shader, "pointLights[0].constant");
	GLint lightLinearLoc =			glGetUniformLocation(shader, "pointLights[0].linear");
	GLint lightQuadraticLoc =		glGetUniformLocation(shader, "pointLights[0].quadratic");
	glUniform1f(lightConstantLoc, constant);
	glUniform1f(lightLinearLoc, linear);
	glUniform1f(lightQuadraticLoc, quadratic);
}

DirectionalLightSource::DirectionalLightSource(Structs::Transform* transform)
{
	type = lightSrc::Directional;
	
	direction = &transform->front;

	ambient = glm::vec3(0.2, 0.2, 0.2);
	diffuse = glm::vec3(0.9, 0.9, 0.9);
	specular = glm::vec3(0.6, 0.6, 0.6);
}

DirectionalLightSource::~DirectionalLightSource()
{
}

void DirectionalLightSource::SetStandardShader(GLuint shader)
{
	GLint lightSpotdirLoc =		glGetUniformLocation(shader, "dirLight.direction");
	SetVec3Unif(lightSpotdirLoc, *direction);

	GLint lightAmbientLoc =		glGetUniformLocation(shader, "dirLight.ambient");
	GLint lightDiffuseLoc =		glGetUniformLocation(shader, "dirLight.diffuse");
	GLint lightSpecularLoc =	glGetUniformLocation(shader, "dirLight.specular");
	SetVec3Unif(lightAmbientLoc, ambient);
	SetVec3Unif(lightDiffuseLoc, diffuse);
	SetVec3Unif(lightSpecularLoc, specular);
}

void DirectionalLightSource::SetLightShader(GLuint shader)
{
	GLint matAmbientLoc = glGetUniformLocation(shader, "ambient");

	glUniform4f(matAmbientLoc, diffuse.x, diffuse.y, diffuse.z, 1);
}


SpotLightSource::SpotLightSource(Structs::Transform* transform)
{
	type = lightSrc::Spot;

	position = &transform->pos;
	direction = &transform->rot;
	cutOff = glm::cos(glm::radians(12.5f));
	outerCutOff = glm::cos(glm::radians(17.5f));

	ambient = glm::vec3(0.1, 0.1, 0.1);
	diffuse = glm::vec3(0.1, 0.1, 0.1);
	specular = glm::vec3(1, 1, 1);

	constant = 1.0f;
	linear = 0.09;
	quadratic = 0.032;
}

SpotLightSource::~SpotLightSource()
{
}

void SpotLightSource::SetStandardShader(GLuint shader)
{
	GLint lightPosLoc =				glGetUniformLocation(shader, "spotLight.position");
	GLint lightSpotdirLoc =			glGetUniformLocation(shader, "spotLight.direction");
	SetVec3Unif(lightPosLoc, *position);
	SetVec3Unif(lightSpotdirLoc, (*direction));

	GLint lightSpotCutOffLoc =		glGetUniformLocation(shader, "spotLight.cutOff");
	GLint lightSpotOuterCutOffLoc = glGetUniformLocation(shader, "spotLight.outerCutOff");
	glUniform1f(lightSpotCutOffLoc, cutOff);
	glUniform1f(lightSpotOuterCutOffLoc, outerCutOff);

	GLint lightAmbientLoc =			glGetUniformLocation(shader, "spotLight.ambient");
	GLint lightDiffuseLoc =			glGetUniformLocation(shader, "spotLight.diffuse");
	GLint lightSpecularLoc =		glGetUniformLocation(shader, "spotLight.specular");
	SetVec3Unif(lightAmbientLoc, ambient);
	SetVec3Unif(lightDiffuseLoc, diffuse);
	SetVec3Unif(lightSpecularLoc, specular);

	GLint lightConstantLoc =		glGetUniformLocation(shader, "spotLight.constant");
	GLint lightLinearLoc =			glGetUniformLocation(shader, "spotLight.linear");
	GLint lightQuadraticLoc =		glGetUniformLocation(shader, "spotLight.quadratic");
	glUniform1f(lightConstantLoc, constant);
	glUniform1f(lightLinearLoc, linear);
	glUniform1f(lightQuadraticLoc, quadratic);
}

void SpotLightSource::SetLightShader(GLuint shader)
{
	GLint matAmbientLoc = glGetUniformLocation(shader, "ambient");

	glUniform4f(matAmbientLoc, diffuse.x, diffuse.y, diffuse.z, 1);
}