#pragma once
#include "resource.h"
#include "Shader.h"
#include "Graphics.h"

#ifndef _SpotLightShader_
#define  _SpotLightShader_
class SpotLightShader : public Shader
{
public:
	SpotLightShader(const std::string& text);
	~SpotLightShader();

	void ShaderUpdate();

	SpotLightSource light;
};
#endif

