#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
using namespace std;

#include <SDL\SDL.h>
#include <gl\glew.h>
#include <glm\glm.hpp>
#include "Graphics.h"
#include "Component.h"

#ifndef _LightSources_
#define  _LightSources_

namespace lightSrc
{
	enum Enum
	{
		None,
		Directional,
		Point,
		Spot
	};
	static map<string, Enum> type = {
		{ "Directional", Directional },
		{ "Point", Point },
		{ "Spot", Spot }
	};
};

class LightSource : public Component
{
public:
	virtual void SetLightShader(GLuint shader) {}
	virtual void SetStandardShader(GLuint shader) {}

	lightSrc::Enum type;

	glm::vec3* position;
	glm::vec3* direction;
	GLfloat cutOff;
	GLfloat outerCutOff;

	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;

	GLfloat constant;
	GLfloat linear;
	GLfloat quadratic;
};

class PointLightSource : public LightSource
{
public:
	PointLightSource(glm::vec3* position);
	PointLightSource(Structs::Transform* transform);
	~PointLightSource();
	void SetLightShader(GLuint shader);
	void SetStandardShader(GLuint shader);
};

class DirectionalLightSource : public LightSource
{
public:
	DirectionalLightSource(glm::vec3* position, glm::vec3* direction);
	DirectionalLightSource(Structs::Transform* transform);
	~DirectionalLightSource();
	void SetLightShader(GLuint shader);
	void SetStandardShader(GLuint shader);
};

class SpotLightSource : public LightSource
{
public:
	SpotLightSource(glm::vec3* position, glm::vec3* direction);
	SpotLightSource(Structs::Transform* transform);
	~SpotLightSource();
	void SetLightShader(GLuint shader);
	void SetStandardShader(GLuint shader);
};
#endif