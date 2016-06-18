#include "LightShader.h"


LightShader::LightShader(Structs::Transform* transform) : Shader("LightShader")
{
	type = sdr::Light;

	this->transform = transform;
	light = new PointLightSource(transform);
	Graphics::instance()->lightSources.push_back(light);
}

LightShader::~LightShader()
{
}

void LightShader::ShaderUpdate()
{
	light->SetLightShader(m_program);
}

void LightShader::SetLightSourceType(lightSrc::Enum type)
{
	if (type != light->type)
	{
		LightSource* newLight = NULL;

		switch (type)
		{
			case lightSrc::Directional:
				newLight = new DirectionalLightSource(transform);
				break;
			case lightSrc::Point:
				newLight = new PointLightSource(transform);
				break;
			case lightSrc::Spot:
				newLight = new SpotLightSource(transform);
				break;
			default:
				break;
		}

		Graphics::instance()->lightSources.remove(light);
		delete light;
		Graphics::instance()->lightSources.push_back(newLight);
		light = newLight;
	}
}