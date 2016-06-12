#pragma once
#include <ctime>
#include "resource.h"
#include "Shader.h"
#include "Graphics.h"
#include "LightSources.h"
#include "Camera.h"

#ifndef _StandardShader_
#define  _StandardShader_
class StandardShader : public Shader
{
public:
	StandardShader(const std::string& text);
	virtual ~StandardShader();

	void ShaderUpdate();
};
#endif

