#include "ScreenShader.h"

ScreenShader::ScreenShader() : Shader("ScreenShader")
{
	type = sdr::Screen;
	bindSettings = sdr::BIND_POS_TEX;

	offset = 300.0f;
	SetPosteffect(scrnSdr::None);
}

ScreenShader::~ScreenShader()
{
}

void ScreenShader::ShaderUpdate()
{
	GLint useKernelLoc = glGetUniformLocation(m_program, "useKernel");
	glUniform1i(useKernelLoc, useKernel);

	if (useKernel)
	{
		GLint offsetLoc = glGetUniformLocation(m_program, "offset");
		glUniform1f(offsetLoc, 1.0f / offset);

		GLint kernelLoc;
		string name, num;

		for (char i = '0'; i <= '8'; i++)
		{
			num = i;
			name = "kernel[" + num + "]";
			kernelLoc = glGetUniformLocation(m_program, name.c_str());
			glUniform1f(kernelLoc, *(currentKernel++));
		}
		currentKernel -= 9;
	}
	else
	{
		GLint simpleEffectTypeLoc = glGetUniformLocation(m_program, "simpleEffectType");
		glUniform1i(simpleEffectTypeLoc, simpleEffectType);
	}
}

void ScreenShader::SetPosteffect(scrnSdr::PosteffectType type)
{	
	curPosteffect = type;

	switch (type)
	{
	case scrnSdr::VCR:
		useKernel = false;
		simpleEffectType = scrnSdr::VCR;
		break;

	case scrnSdr::Invert:
		useKernel = false;
		simpleEffectType = scrnSdr::Invert;
		break;

	case scrnSdr::Grayscale:
		useKernel = false;
		simpleEffectType = scrnSdr::Grayscale;
		break;

	case scrnSdr::None:
		useKernel = false;
		simpleEffectType = scrnSdr::None;
		break;

	case scrnSdr::ParticularSharpen:
		useKernel = true;
		currentKernel = scrnSdr::particularSharpen;
		break;

	case scrnSdr::Blur:
		useKernel = true;
		currentKernel = scrnSdr::blur;
		break;

	case scrnSdr::EdgesHighlight:
		useKernel = true;
		currentKernel = scrnSdr::edgesHighlight;
		break;

	default:
		useKernel = false;
		simpleEffectType = scrnSdr::None;
		break;
	}
}
