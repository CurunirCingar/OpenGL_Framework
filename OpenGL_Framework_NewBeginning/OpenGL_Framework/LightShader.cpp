#include "LightShader.h"


LightShader::LightShader(std::string& text, Structs::Transform* transform) : Shader(text)
{
	type = ShaderTypes::Light;

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

void LightShader::SetLightSourceType(LightSources::Type type)
{
	if (type != light->type)
	{
		LightSource* newLight = NULL;

		switch (type)
		{
			case LightSources::Directional:
				newLight = new DirectionalLightSource(transform);
				break;
			case LightSources::Point:
				newLight = new PointLightSource(transform);
				break;
			case LightSources::Spot:
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