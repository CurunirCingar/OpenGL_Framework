#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include <SDL\SDL.h>
#include <gl\glew.h>
#include <glm\glm.hpp>

#include "Graphics.h"
#include "ScreenShader.h"

class Framebuffer
{
public:
	Framebuffer();
	~Framebuffer();

	void BindBuffer();
	void Update();
	GLuint generateAttachmentTexture(GLboolean depth, GLboolean stencil);

	ScreenShader* shader;

private:
	GLuint framebuffer;
	GLuint texColorBuffer;
	GLuint RBO;
	GLuint VAO;
	GLuint VBO;
};

