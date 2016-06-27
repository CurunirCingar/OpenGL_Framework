#pragma once
#include <sstream>
#include "Shader.h"

namespace scrnSdr{

	const GLfloat particularSharpen[9] = {
		-1, -1, -1,
		-1, 9, -1,
		-1, -1, -1
	};

	const GLfloat blur[9] = {
		1.0 / 16, 2.0 / 16, 1.0 / 16,
		2.0 / 16, 4.0 / 16, 2.0 / 16,
		1.0 / 16, 2.0 / 16, 1.0 / 16
	};

	const GLfloat edgesHighlight[9] = {
		1, 1, 1,
		1, -9, 1,
		1, 1, 1
	};

	enum PosteffectType{
		VCR,
		Invert,
		Grayscale,
		None,

		ParticularSharpen,
		Blur,
		EdgesHighlight
	};
};

class ScreenShader : public Shader
{
	const string fileName = "ScreenShader";

public:
	ScreenShader();
	~ScreenShader();

	void ShaderUpdate();
	void SetPosteffect(scrnSdr::PosteffectType type);

	scrnSdr::PosteffectType curPosteffect;

	GLfloat offset;
	const GLfloat* currentKernel;
	GLboolean useKernel;
	GLuint simpleEffectType;

};

