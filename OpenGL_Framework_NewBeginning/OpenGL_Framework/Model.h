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

#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>
#include "Mesh.h"

class Model
{
public:
	Model(const std::string& path, Shader* shader);
	~Model();
	void Draw();

private:
	void LoadModel(const std::string& path);
	void ProcessNode(aiNode* node, const aiScene* scene);
	Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
	vector<Structs::Texture> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);
	GLint TextureFromFile(const char* path, string directory);

	Shader* shader;
	vector<Mesh> meshes;
	string directory;
	vector<Structs::Texture> textures_loaded;
};