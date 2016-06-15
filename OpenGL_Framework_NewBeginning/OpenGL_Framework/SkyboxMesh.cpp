#include "SkyboxMesh.h"


SkyboxMesh::SkyboxMesh(vector<Structs::Vertex> vertices, vector<GLuint> indices, vector<Structs::Texture> textures, GLuint shaderProgram)
: Mesh(vertices, indices, textures, shaderProgram)
{
}


SkyboxMesh::~SkyboxMesh()
{
}

void SkyboxMesh::Update()
{
	//glPolygonMode(GL_FRONT_AND_BACK, m_polygonMode);

	glBindVertexArray(VAO);
	glDepthMask(0);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[0].id);
	string name = "material.texture_diffuse1";
	GLuint texLoc = glGetUniformLocation(m_shaderProgram, name.c_str());
	glUniform1i(texLoc, 0);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	glDepthMask(1);
	glBindVertexArray(0);
}