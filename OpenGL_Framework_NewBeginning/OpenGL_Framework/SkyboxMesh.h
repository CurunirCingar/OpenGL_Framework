#pragma once
#include "Mesh.h"
class SkyboxMesh : public Mesh
{
public:
	SkyboxMesh(vector<Structs::Vertex> vertices, vector<GLuint> indices, vector<Structs::Texture> textures, GLuint shaderProgram);
	~SkyboxMesh();
	void Draw();
};

