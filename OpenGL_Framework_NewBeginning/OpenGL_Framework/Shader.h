#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
#include <SDL\SDL.h>
#include <gl\glew.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#ifndef _Shader_
#define  _Shader_

namespace sdr
{
	enum Enum
	{
		Standard,
		StandardBlended,
		Light,
		Skybox,
		Reflective
	};
	static map<string, Enum> type = {
		{ "StandardShader", Standard },
		{ "StandardBlendedShader", StandardBlended },
		{ "LightShader", Light },
		{ "SkyboxShader", Skybox },
		{ "ReflectiveShader", Reflective },
	};
};


class Shader
{
public:
	Shader(const std::string& text);
	virtual ~Shader();

	sdr::Enum type;

	void Update();
	inline GLuint GetProgramID() { return m_program; }
	
protected:
	
	GLuint CreateShader(const std::string& filename, GLenum shaderType);
	void LoadShader(GLuint shaderID, const std::string& filename);
	void CheckShaderError(GLuint shader, bool isProgram, GLuint flag, const std::string& errorMessage);
	virtual void ShaderUpdate() = 0;

	enum{
		VERTEX,
		FRAGMENT,

		NUM_SHADERS
	};

	enum{
		POSITION_ATTRIB,
		NORMAL_ATTRIB,
		COLOR_ATTRIB,
		TEXTURECOORD_ATTRIB,

		NUM_ATTRIBS
	};

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
};
#endif


