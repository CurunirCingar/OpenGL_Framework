#pragma once
#include "Shader.h"
#include "Camera.h"

class ReflectiveShader : public Shader
{
public:
	ReflectiveShader();
	~ReflectiveShader();
	void ShaderUpdate();
};

