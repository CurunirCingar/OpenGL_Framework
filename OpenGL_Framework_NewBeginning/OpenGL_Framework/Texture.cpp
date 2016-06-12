#include "Texture.h"

Texture::Texture(GLuint texturesCount, std::string* textureFilename, GLuint program)
{
	m_texturesCount = texturesCount;
	m_shaderProgram = program;
	texturesUniformsNames = new std::string[2];
	texturesUniformsNames[0] = "ourTexture0";
	texturesUniformsNames[1] = "ourTexture1";

	m_textures = new GLuint();
	glGenTextures(1, m_textures);

	for (GLuint i = 0; i < m_texturesCount; i++)
	{
		glBindTexture(GL_TEXTURE_2D, m_textures[i]);
		LoadTexture(textureFilename[i].c_str());
	}	
}


void Texture::LoadTexture(std::string textureFilename)
{
	int width, height, numComponents;
	unsigned char* imageData = stbi_load(textureFilename.c_str(), &width, &height, &numComponents, 3);

	if (imageData == NULL)
	{
		std::cout << "Can't load image " + textureFilename;
		return;
	}

	

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(imageData);
	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture()
{
	delete[] texturesUniformsNames;
}

void Texture::Update()
{
	glUniform1i(glGetUniformLocation(m_shaderProgram, "material.diffuse"), 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_textures[0]);

	glUniform1i(glGetUniformLocation(m_shaderProgram, "material.specular"), 1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, m_textures[1]);
}