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
#include "Camera.h"

#ifndef _Transform_
#define  _Transform_
class Transform
{
public:
	Transform();
	~Transform();

	void Start();
	void Update();
	inline void SetProgramID(GLuint program) { m_program = program; }

	void SetPosition(glm::vec3& position);
	void SetRotation(glm::vec3& rotation);
	void SetRotationOnAxis(GLfloat rotationAngle, glm::vec3& rotationAxis); 
	void SetScale(glm::vec3& scale);
	void RotateAround(GLfloat rotationAngle, glm::vec3& rotationAxis);

	GLuint m_program;
	
	Structs::Transform transform;
	glm::vec3 m_scale;
	GLfloat m_rotationAngle;
	glm::vec3 m_rotationAxis;
	glm::mat4* cameraViewMatrix;

	glm::vec3 xRot, yRot, zRot;
};
#endif

