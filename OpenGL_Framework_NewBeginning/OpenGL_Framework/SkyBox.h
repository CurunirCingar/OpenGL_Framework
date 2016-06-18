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

#include "SkyboxMesh.h"
#include "GeneratedMesh.h"

class Skybox : public GeneratedMesh
{
public:
	Skybox(vector<string>& texFilenames, sdr::Enum shaderType);
	~Skybox();

	void SetupMesh(vector<string>& textures);
	void Update();
};

