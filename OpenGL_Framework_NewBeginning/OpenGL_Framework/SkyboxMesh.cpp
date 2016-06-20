#include "SkyboxMesh.h"


SkyboxMesh::SkyboxMesh(vector<Structs::Vertex> vertices, vector<GLuint> indices, vector<Structs::Texture> textures, GLuint shaderProgram)
	: Mesh( vertices, indices, textures, shaderProgram)
{

}


SkyboxMesh::~SkyboxMesh()
{

}

void SkyboxMesh::SetupMesh()
{
	m_polygonMode = GL_FILL;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Structs::Vertex), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(POSITION_VB, 3, GL_FLOAT, GL_FALSE, sizeof(Structs::Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(POSITION_VB);

	glBindVertexArray(0);
}

void SkyboxMesh::Draw()
{
	glActiveTexture(GL_TEXTURE0);
	GLuint cubemapTexLoc = glGetUniformLocation(m_shaderProgram, "skybox");
	glUniform1i(cubemapTexLoc, 0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textures[0].id);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
