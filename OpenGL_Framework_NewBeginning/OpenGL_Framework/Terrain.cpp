#include "Terrain.h"


Terrain::Terrain(vector<string>& texFilenames, int& tileSize, int& textureTiling, sdr::Enum shaderType) : GeneratedMesh(shaderType)
{
	this->tileSize = tileSize;
	this->textureTiling = textureTiling;
	SetupMesh(texFilenames);
	transform->SetScale(glm::vec3(0.3, 0.3, 0.3));
	((StandardBlendedShader*)(shaders[0]))->shininess = 2;
}

Terrain::~Terrain()
{
	
}

void Terrain::SetupMesh(vector<string>& texFilenames)
{
	// Textures
	vector<Structs::Texture> textures;
	vector<float> heightsArr;
	Structs::Texture bufTex;
	int terrainWidth, terrainHeight;

	bufTex.id = LoadTexture(texFilenames[0]);
	bufTex.type = "texture_diffuse";
	textures.push_back(bufTex);

	bufTex.id = LoadTexture(texFilenames[1], terrainWidth, terrainHeight, heightsArr);
	bufTex.type = "texture_diffuse";
	textures.push_back(bufTex);

	// Vertices
	vector<Structs::Vertex> vertices;
	Structs::Vertex bufVertex;
	int tilesAmount = terrainWidth / tileSize;
	int x, y;
	glm::vec3 posBuf[6], normalBuf[2];

	for (int i = 0; i < terrainWidth; i += tileSize)
	{
		for (int j = 0; j < terrainWidth; j += tileSize)
		{
			x = (j == terrainWidth - tileSize) ? (j - tileSize) : j;
			y = (i == terrainWidth - tileSize) ? (i - tileSize) : i;
			posBuf[0] = glm::vec3(x, heightsArr[x*terrainWidth + y], y);
			posBuf[1] = glm::vec3(x + tileSize, heightsArr[(x + tileSize)*terrainWidth + y], y);
			posBuf[2] = glm::vec3(x + tileSize, heightsArr[(x + tileSize)*terrainWidth + (y + tileSize)], y + tileSize);			
			
			normalBuf[0] = glm::cross(posBuf[0] - posBuf[1], posBuf[1] - posBuf[2]);
			normalBuf[0] = glm::normalize(-normalBuf[0]);

			vertices.push_back(Structs::Vertex() =
			{ 
				posBuf[2],
				normalBuf[0],
				glm::vec2(0, 0) 
			});
			vertices.push_back(Structs::Vertex() =
			{ 
				posBuf[1],
				normalBuf[0],
				glm::vec2(1, 0) 
			});
			vertices.push_back(Structs::Vertex() =
			{ 
				posBuf[0],
				normalBuf[0],
				glm::vec2(1, 1) 
			});

			posBuf[3] = glm::vec3(x + tileSize, heightsArr[(x + tileSize)*terrainWidth + (y + tileSize)], y + tileSize);
			posBuf[4] = glm::vec3(x, heightsArr[x*terrainWidth + (y + tileSize)], y + tileSize);
			posBuf[5] = glm::vec3(x, heightsArr[x*terrainWidth + y], y);
			normalBuf[1] = glm::cross(posBuf[3] - posBuf[4], posBuf[3] - posBuf[5]);
			normalBuf[1] = glm::normalize(-normalBuf[1]);
			
			vertices.push_back(Structs::Vertex() =
			{ 
				posBuf[5],
				normalBuf[1],
				glm::vec2(1, 1) 
			});
			vertices.push_back(Structs::Vertex() =
			{ 
				posBuf[4],
				normalBuf[1],
				glm::vec2(0, 1) 
			});
			vertices.push_back(Structs::Vertex() =
			{ 
				posBuf[3],
				normalBuf[1],
				glm::vec2(0, 0) 
			});
		}
	}

	// Indices
	vector<GLuint> indices;
	int N = tilesAmount*tilesAmount * 6;

	for (GLuint k = 0; k < N; k++)
		indices.push_back(k);

	vector<Structs::Vertex> meshVertices;
	vector<GLuint> meshIndices;
	vector<Structs::Texture> meshTextures;

	meshTextures.assign(1, textures[0]);

	meshes.push_back(new Mesh(vertices, indices, meshTextures, shaders[0]->GetProgramID()));
}

void Terrain::Update()
{
	shaders[0]->Update();
	transform->Update();
	meshes[0]->Draw();
}

GLuint Terrain::LoadTexture(string filename, int& width, int& height, vector<float>& heightsArr)
{
	GLuint textureID;
	glGenTextures(1, &textureID);
	int numComponents;
	unsigned char* image = stbi_load(filename.c_str(), &width, &height, &numComponents, 3);

	unsigned char* imagePixel = image;
	float grayscale;
	unsigned char r, g, b;
	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		r = *(imagePixel);
		g = *(imagePixel+1);
		b = *(imagePixel+2);

		grayscale = (float)(r+g+b)/15.0f;
		heightsArr.push_back(grayscale);
		imagePixel += 3;
	}
	// Assign texture to ID
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	// Parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(image);
	return textureID;
}

GLuint Terrain::LoadTexture(string filename)
{
	GLuint textureID;
	glGenTextures(1, &textureID);
	int width, height, numComponents;
	unsigned char* image = stbi_load(filename.c_str(), &width, &height, &numComponents, 4);

	// Assign texture to ID
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	// Parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(image);
	return textureID;
}