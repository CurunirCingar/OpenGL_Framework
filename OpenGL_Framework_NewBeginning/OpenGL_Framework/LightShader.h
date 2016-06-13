#pragma once
#include "resource.h"
#include "Shader.h"
#include "Graphics.h"
#include "LightSources.h"

#ifndef _LightShader_
#define  _LightShader_
class LightShader : public Shader
{
public:
	LightShader(std::string& text, Structs::Transform* transform);
	virtual ~LightShader();

	void ShaderUpdate();
	void SetLightSourceType(LightSources::Type type);

	LightSource* light;
	Structs::Transform* transform;
};
#endif
