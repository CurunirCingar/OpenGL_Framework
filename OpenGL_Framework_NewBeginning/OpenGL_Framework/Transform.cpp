#include "Transform.h"

Transform::Transform()
{
	transform.pos = glm::vec3(0, 0, 0);
	transform.rot = glm::vec3(0, 0, 0);
	m_scale = glm::vec3(1, 1, 1);
	m_rotationAngle = 0;

	xRot = glm::vec3(1, 0, 0);
	yRot = glm::vec3(0, 1, 0);
	zRot = glm::vec3(0, 0, 1);
}

void Transform::Start()
{
	cameraViewMatrix = ((Camera*)(Graphics::instance()->MainCamera))->GetViewMatrix();
}

Transform::~Transform()
{
}

void Transform::Update()
{
	glm::mat4 view;
	view = *cameraViewMatrix;

	glm::mat4 model;

	
	model = glm::translate(model, transform.pos);
	
	model = glm::scale(model, m_scale);

	model = glm::rotate(model, glm::radians(transform.rot.x), xRot);
	model = glm::rotate(model, glm::radians(transform.rot.y), yRot);
	model = glm::rotate(model, glm::radians(transform.rot.z), zRot);
	

	glm::mat4 projection;
	projection = glm::perspective(45.0f, 1000.0f / 600.0f, 0.5f, 500.0f);

	GLint viewLoc = glGetUniformLocation(m_program, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	GLint modelLoc = glGetUniformLocation(m_program, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	GLint projectionLoc = glGetUniformLocation(m_program, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

void Transform::SetPosition(glm::vec3& position)
{
	transform.pos = position;
}

void Transform::SetRotation(glm::vec3& rotation)
{
	transform.rot = rotation;
}

void Transform::SetRotationOnAxis(GLfloat rotationAngle, glm::vec3& rotationAxis)
{
	m_rotationAngle = rotationAngle;
	m_rotationAxis = rotationAxis;
}

void Transform::SetScale(glm::vec3& scale)
{
	m_scale = scale;
}

void Transform::RotateAround(GLfloat rotationAngle, glm::vec3& rotationAxis)
{
	m_rotationAngle += rotationAngle;
	m_rotationAngle = (m_rotationAngle > 360) ? (m_rotationAngle - 360) : m_rotationAngle;
	m_rotationAxis = rotationAxis;
}