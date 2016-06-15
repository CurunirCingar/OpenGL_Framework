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

#include "GeneratedMesh.h"
#include "Transform.h"

class Terrain : public GeneratedMesh
{
public:
	Terrain(vector<string>& texFilenames, ShaderTypes::Enum shaderType);
	~Terrain();

	void SetupMesh(vector<string>& textures);
	void Update();
};

