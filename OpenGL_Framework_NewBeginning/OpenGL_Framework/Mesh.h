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

#include "VerticesBlockT.h"
#include "Material.h"
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

	Mesh(const std::string& shaderFilename, const std::string& verticesFilename, GLuint shaderProgram);
	Mesh(vector<Structs::Vertex> vertices, vector<GLuint> indices, vector<Structs::Texture> textures, GLuint shaderProgram);
	void Draw();
	virtual ~Mesh();

	void Update();
	void ChangePolygonMode();

	VerticesBlockT* verticesInfo;
	//Material* material;
	Texture* texture;

private:
	void SetupMesh();

	GLuint m_shaderProgram;
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	GLuint m_polygonMode;
};
#endif
