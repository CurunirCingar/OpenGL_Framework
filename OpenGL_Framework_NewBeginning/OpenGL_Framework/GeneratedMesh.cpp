#include "GeneratedMesh.h"


GeneratedMesh::GeneratedMesh(vector<string>& texFilenames, sdr::Enum shaderType)
{
	int len = texFilenames.size();

	transform = new Transform();
	switch (shaderType)
	{
	case sdr::Standard:
		for (int i = 0; i < len; i++)
			shaders.push_back(new StandardShader());
		break;
	case sdr::StandardBlended:
		for (int i = 0; i < len; i++)
			shaders.push_back(new StandardBlendedShader());
		break;
	case sdr::Light:
		for (int i = 0; i < len; i++)
			shaders.push_back(new LightShader(&transform->transform));
		break;
	default:
		break;
	}

	transform->SetProgramID(shaders[0]->GetProgramID());
}

GeneratedMesh::GeneratedMesh(sdr::Enum shaderType)
{
	transform = new Transform();

	switch (shaderType)
	{
	case sdr::Standard:
		shaders.push_back(new StandardShader());
		break;
	case sdr::StandardBlended:
		shaders.push_back(new StandardBlendedShader());
		break;
	case sdr::Light:
		shaders.push_back(new LightShader(&transform->transform));
		break;
	default:
		break;
	}

	transform->SetProgramID(shaders[0]->GetProgramID());
}


GeneratedMesh::~GeneratedMesh()
{
}

GLuint GeneratedMesh::LoadTexture(string filename)
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

void GeneratedMesh::Start()
{
	transform->Start();
}