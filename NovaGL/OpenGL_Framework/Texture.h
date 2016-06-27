#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include <SDL\SDL.h>
#include <gl\glew.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "stb_image.h"

#ifndef _Texture_
#define  _Texture_
class Texture
{
public:
	Texture(GLuint texturesCount, std::string* textureFilename, GLuint program);
	~Texture();

	void LoadTexture(std::string textureFilename);

	void Update();

	GLuint* m_textures;
	GLuint m_texturesCount;
	GLuint m_shaderProgram;

	std::string* texturesUniformsNames;
};
#endif
