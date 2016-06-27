#pragma once
#include "resource.h"
#include "Shader.h"
#include "Graphics.h"
#include "LightSources.h"

#ifndef _LightShader_
#define  _LightShader_
class LightShader : public Shader
{
	const string fileName = "LightShader";
public:
	LightShader(Structs::Transform* transform);
	virtual ~LightShader();

	void ShaderUpdate();
	void SetLightSourceType(lightSrc::Enum type);

	LightSource* light;
	Structs::Transform* transform;
};
#endif
