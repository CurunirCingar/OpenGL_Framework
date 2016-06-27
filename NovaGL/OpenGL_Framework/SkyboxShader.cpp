#include "SkyboxShader.h"


SkyboxShader::SkyboxShader() : Shader("SkyboxShader")
{
	type = sdr::Light;
	bindSettings = sdr::BIND_POS;
}


SkyboxShader::~SkyboxShader()
{
}

void SkyboxShader::ShaderUpdate()
{
	
}
