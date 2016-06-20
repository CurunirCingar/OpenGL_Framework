#pragma once
#include "Shader.h"
class SkyboxShader : public Shader
{
	const string fileName = "SkyboxShader";
public:
	SkyboxShader();
	~SkyboxShader();

	void ShaderUpdate();
};

