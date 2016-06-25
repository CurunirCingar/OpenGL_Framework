#include "Skybox.h"


Skybox::Skybox(vector<string>& texFilenames, sdr::Enum shaderType) : GeneratedGameObject(shaderType)
{
	transform->SetScale(glm::vec3(2, 2, 2));
	SetupMesh(texFilenames);
}

Skybox::~Skybox()
{
}

void Skybox::SetupMesh(vector<string>& texFilenames)
{
	vector<Structs::Vertex> vertices = {
		// Right
		{ glm::vec3(-1, -1, -1), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0, 0) },
		{ glm::vec3(1, -1, -1), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1, 0) },
		{ glm::vec3(1, 1, -1), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1, 1) },
		{ glm::vec3(1, 1, -1), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1, 1) },
		{ glm::vec3(-1, 1, -1), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0, 1) },
		{ glm::vec3(-1, -1, -1), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0, 0) },

		// Left
		{ glm::vec3(1, 1, 1), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0, 1) },
		{ glm::vec3(1, -1, 1), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0, 0) },
		{ glm::vec3(-1, -1, 1), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1, 0) },
		{ glm::vec3(-1, -1, 1), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1, 0) },
		{ glm::vec3(-1, 1, 1), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1, 1) },
		{ glm::vec3(1, 1, 1), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0, 1) },

		// Up
		{ glm::vec3(-1, 1, 1), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0, 1) },
		{ glm::vec3(1, 1, -1), glm::vec3(0.0f, 1.0f, 0.0), glm::vec2(1, 1) },
		{ glm::vec3(1, 1, 1), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1, 0) },
		{ glm::vec3(1, 1, -1), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1, 1) },
		{ glm::vec3(-1, 1, 1), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0, 1) },
		{ glm::vec3(-1, 1, -1), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0, 1) },
		

		// Down
		{ glm::vec3(1, -1, 1), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1, 1) },
		{ glm::vec3(1, -1, -1), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1, 0) },
		{ glm::vec3(-1, -1, -1), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0, 0) },
		{ glm::vec3(-1, -1, -1), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0, 0) },
		{ glm::vec3(-1, -1, 1), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0, 1) },
		{ glm::vec3(1, -1, 1), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1, 1) },

		// Back
		{ glm::vec3(-1, -1, -1), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1, 0) },
		{ glm::vec3(-1, 1, -1), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1, 1) },
		{ glm::vec3(-1, 1, 1), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0, 1) },
		{ glm::vec3(-1, 1, 1), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0, 1) },
		{ glm::vec3(-1, -1, 1), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0, 0) },
		{ glm::vec3(-1, -1, -1), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1, 0) },

		// Front
		{ glm::vec3(1, 1, 1), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1, 1) },
		{ glm::vec3(1, 1, -1), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0, 1) },
		{ glm::vec3(1, -1, -1), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0, 0) },
		{ glm::vec3(1, -1, -1), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0, 0) },
		{ glm::vec3(1, -1, 1), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1, 0) },
		{ glm::vec3(1, 1, 1), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1, 1) },

		
	};

	vector<GLuint> indices = {
		0, 1, 2,
		3, 4, 5,

		6, 7, 8,
		9, 10, 11,

		12, 13, 14,
		15, 16, 17,

		18, 19, 20,
		21, 22, 23,

		24, 25, 26,
		27, 28, 29,

		30, 31, 32,
		33, 34, 35,
	};

	vector<Structs::Texture> textures;
	Structs::Texture cubemapTex;

	GLuint textureID;
	glGenTextures(1, &textureID);

	for (int i = 0; i < 6; i++)
		cubemapTex.id = LoadCubemapTexture(textureID, texFilenames[i], i);
	cubemapTex.shaderName = "texture_diffuse";
	cubemapTex.type = GL_TEXTURE_CUBE_MAP;

	Graphics::instance()->Terrain = (void*)(&cubemapTex.id);

	textures.push_back(cubemapTex);

	meshes.push_back(new Mesh(vertices, indices, textures, shaders[0]->GetProgramID(), Mesh::BIND_POS));
}

void Skybox::Update()
{
	glDepthFunc(GL_LEQUAL);
	shaders[0]->Update();
	transform->Update();
	meshes[0]->Draw();
	glDepthFunc(GL_LESS);
}

GLuint Skybox::LoadCubemapTexture(GLuint textureID, string filename, GLuint i)
{
	
	int width, height, numComponents;
	unsigned char* image = stbi_load(filename.c_str(), &width, &height, &numComponents, 3);

	// Assign texture to ID
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	// Parameters
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	stbi_image_free(image);
	return textureID;
}