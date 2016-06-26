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
#include "ReflectiveShader.h"
#include "RefractiveShader.h"
#include "ScreenShader.h"

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

	Mesh(vector<Structs::Vertex> vertices, vector<GLuint> indices, vector<Structs::Texture> textures, Shader* shader);
	virtual void Draw();
	virtual ~Mesh();

	void ChangePolygonMode();
	static Shader* CreateShader(std::string& shaderFilename, Structs::Transform* transform);

protected:
	virtual void SetupMesh();

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	Shader* shader;
	GLuint polygonMode;
};
#endif
