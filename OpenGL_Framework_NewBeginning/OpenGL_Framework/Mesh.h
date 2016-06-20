#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <SDL\SDL.h>
#include <gl\glew.h>
#include <glm\glm.hpp>

#include "stb_image.h"

#include "Shader.h"
#include "StandardShader.h"
#include "LightShader.h"
#include "StandardBlendedShader.h"
#include "SkyboxShader.h"
#include "Graphics.h"

#ifndef _Mesh_
#define  _Mesh_

class Mesh
{
public:
	enum{
		POSITION_VB,
		NORMAL_VB,
		TEXTURECOORD_VB,

		NUM_BUFFERS
	};

	vector<Structs::Vertex> vertices;
	vector<GLuint> indices;
	vector<Structs::Texture> textures;

	Mesh(vector<Structs::Vertex> vertices, vector<GLuint> indices, vector<Structs::Texture> textures, GLuint shaderProgram);
	virtual void Draw();
	virtual ~Mesh();

	void ChangePolygonMode();

protected:
	virtual void SetupMesh();

	GLuint m_shaderProgram;
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	GLuint m_polygonMode;
};
#endif
