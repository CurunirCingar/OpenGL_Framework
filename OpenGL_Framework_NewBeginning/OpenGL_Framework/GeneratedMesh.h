#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include <SDL\SDL.h>
#include <gl\glew.h>
#include <glm\glm.hpp>
#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

#include "Transform.h"
#include "Mesh.h"

class GeneratedMesh
{
public:
	GeneratedMesh(vector<string>& textures, ShaderTypes::Enum shaderType);
	GeneratedMesh(ShaderTypes::Enum shaderType);
	~GeneratedMesh();

	void Start();
	GLuint LoadTexture(string filename);

	virtual void SetupMesh(vector<string>& textures) = 0;
	virtual void Update() = 0;

	vector<Shader*> shaders;
	Transform* transform;
	vector<Mesh*> meshes;

	GLuint shaderProgram;
};

