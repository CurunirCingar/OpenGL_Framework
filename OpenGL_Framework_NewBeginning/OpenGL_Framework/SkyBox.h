#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

#include <SDL\SDL.h>
#include <gl\glew.h>
#include <glm\glm.hpp>
#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>
//#include "stb_image.h"

#include "Mesh.h"
#include "Transform.h"

class SkyBox
{
public:
	SkyBox(string& fileBase, string& front, string& back, string& left, string& right, string& top, string& bottom);
	~SkyBox();

	void SetupMesh(string& fileBase, string& front, string& back, string& left, string& right, string& top, string& bottom);
	GLuint LoadTexture(string filename);

	void Start();
	void Update();

	vector<Shader*> shaders;
	vector<Transform*> transforms;
	vector<Mesh*> meshes;

	GLuint shaderProgram;
};

