#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include <SDL\SDL.h>
#include <gl\glew.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Graphics.h"
#include "Component.h"

#ifndef _Camera_
#define  _Camera_

class Camera : public Component
{
public:
	Camera(Structs::Transform* transform);
	virtual ~Camera();

	void Move(GLint xShift, GLint yShift);
	void Rotate(GLint xPos, GLint yPos);

	inline glm::mat4* GetViewMatrix() { return &view; }

	Structs::Transform* transform;
private:
	glm::mat4 view;
	glm::vec3 front;
	glm::vec3 up;

	glm::vec3 cameraUp;

	glm::vec3 cameraTarget;
	glm::vec3 cameraDirection;

	glm::vec3 cameraRight;

	GLfloat speed;
	GLboolean isSetted;

	GLuint lastX;
	GLuint lastY;
	GLfloat pitch;
	GLfloat yaw;

	GLuint* width;
	GLuint* height;
};
#endif
