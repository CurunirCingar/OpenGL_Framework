#pragma once
#include "Shader.h"
#include "Camera.h"

class RefractiveShader : public Shader
{
public:
	RefractiveShader();
	~RefractiveShader();

	void ShaderUpdate();

	GLfloat ratio;
};

