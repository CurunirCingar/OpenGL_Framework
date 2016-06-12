#include "Camera.h"

Camera::Camera(Structs::Transform* transform)
{
	this->transform = transform;

	yaw = 90;
	pitch = 0;
	isSetted = false;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	transform->rot = glm::normalize(-front);

	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	cameraDirection = glm::normalize(transform->pos - cameraTarget);

	cameraRight = glm::normalize(glm::cross(cameraUp, cameraDirection));
	cameraUp = glm::cross(cameraDirection, cameraRight);

	view = glm::lookAt(transform->pos, transform->pos + transform->rot, cameraUp);

	speed = 0.05f;
}


Camera::~Camera()
{
}

void Camera::Move(GLint xShift, GLint yShift)
{
	if (xShift)
		transform->pos += xShift * speed * glm::cross(transform->rot, cameraUp);
	if (yShift)
		transform->pos += yShift * speed * transform->rot;
	
	view = glm::lookAt(transform->pos, transform->pos + transform->rot, cameraUp);
}

void Camera::Rotate(GLint xPos, GLint yPos)
{
	if (!isSetted)
	{
		isSetted = true;
		return;
	}

	GLfloat sensitivity = 0.15f;
	yaw += xPos * sensitivity;
	pitch += yPos * sensitivity;
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	transform->rot = glm::normalize(-front);
	view = glm::lookAt(transform->pos, transform->pos + transform->rot, cameraUp);
}