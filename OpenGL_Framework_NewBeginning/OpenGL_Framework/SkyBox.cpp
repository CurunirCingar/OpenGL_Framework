#include "SkyBox.h"


SkyBox::SkyBox(string& fileBase, string& front, string& back, string& left, string& right, string& top, string& bottom)
{
	transforms.push_back(new Transform());
	for (int i = 0; i < 6; i++)
	{
		
		shaders.push_back(new LightShader((string)"LightShader", &transforms[0]->transform));
		
	}
	transforms[0]->SetProgramID(shaders[0]->GetProgramID());
	transforms[0]->m_scale = glm::vec3(500, 500, 500);

	SetupMesh(fileBase, front, back, left, right, top, bottom);
}

SkyBox::~SkyBox()
{
}

void SkyBox::SetupMesh(string& fileBase, string& front, string& back, string& left, string& right, string& top, string& bottom)
{
	vector<Structs::Vertex> vertices = {
		// Back
		{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0, 0) },
		{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1, 0) },
		{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1, 1) },
		{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1, 1) },
		{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0, 1) },
		{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0, 0) },

		// Front
		{ glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1, 0) },
		{ glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0, 0) },
		{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0, 1) },
		{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0, 1) },
		{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1, 1) },
		{ glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1, 0) },

		// Left
		{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0, 1) },
		{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1, 1) },
		{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1, 0) },
		{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1, 0) },
		{ glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0, 0) },
		{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0, 1) },

		// Right
		{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1, 1) },
		{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0, 1) },
		{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0, 0) },
		{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0, 0) },
		{ glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1, 0) },
		{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1, 1) },

		// Bottom
		{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0, 0) },
		{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1, 0) },
		{ glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1, 1) },
		{ glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1, 1) },
		{ glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0, 1) },
		{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0, 0) },

		// Top
		{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0), glm::vec2(0, 0) },
		{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1, 0) },
		{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1, 1) },
		{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1, 1) },
		{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0, 1) },
		{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0, 0) },
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
	Structs::Texture bufTex;

	bufTex.id = LoadTexture(fileBase + front);
	bufTex.type = "texture_diffuse1";
	textures.push_back(bufTex);

	bufTex.id = LoadTexture(fileBase + back);
	bufTex.type = "texture_diffuse1";
	textures.push_back(bufTex);

	bufTex.id = LoadTexture(fileBase + left);
	bufTex.type = "texture_diffuse1";
	textures.push_back(bufTex);

	bufTex.id = LoadTexture(fileBase + right);
	bufTex.type = "texture_diffuse1";
	textures.push_back(bufTex);

	bufTex.id = LoadTexture(fileBase + bottom);
	bufTex.type = "texture_diffuse1";
	textures.push_back(bufTex);

	bufTex.id = LoadTexture(fileBase + top);
	bufTex.type = "texture_diffuse1";
	textures.push_back(bufTex);

	vector<Structs::Vertex> meshVertices;
	vector<GLuint> meshIndices;
	vector<Structs::Texture> meshTextures;

	for (int i = 0; i < 6; i++)
	{
		meshVertices.assign( vertices.begin() + 6*i, vertices.begin() + 6*(i+1) );
		meshIndices.assign( indices.begin(), indices.begin() + 6 );
		meshTextures.assign( 1, textures[i] );

		meshes.push_back(new Mesh(meshVertices, meshIndices, meshTextures, shaders[i]->GetProgramID()));
	}
}

GLuint SkyBox::LoadTexture(string filename)
{
	GLuint textureID;
	glGenTextures(1, &textureID);
	int width, height, numComponents;
	unsigned char* image = stbi_load(filename.c_str(), &width, &height, &numComponents, 3);
	// Assign texture to ID
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	// Parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(image);
	return textureID;
}

void SkyBox::Start()
{
	//for (int i = 0; i < 6; i++)
		transforms[0]->Start();
}

void SkyBox::Update()
{
	for (int i = 0; i < 6; i++)
	{
		shaders[i]->Update();
		transforms[0]->Update();
		meshes[i]->Update();
	}
}
