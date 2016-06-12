#include "Mesh.h"

Mesh::Mesh(vector<Structs::Vertex> vertices, vector<GLuint> indices, vector<Structs::Texture> textures, GLuint shaderProgram)
{
	m_shaderProgram = shaderProgram;

	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

	SetupMesh();
}

Mesh::Mesh(const std::string& shaderFilename, const std::string& verticesFilename, GLuint shaderProgram)
{
	m_shaderProgram = shaderProgram;

	verticesInfo = new VerticesBlockT(verticesFilename);
	//material = new Material(verticesInfo, shaderFilename, transform);
	texture = new Texture(verticesInfo->m_texturesFilesArrLen, verticesInfo->m_texturesFilesArr, m_shaderProgram);

	m_polygonMode = GL_FILL;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, verticesInfo->m_verticesSize * sizeof(verticesInfo->m_vertices[0]), verticesInfo->m_vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, verticesInfo->m_indicesSize * sizeof(verticesInfo->m_indices[0]), verticesInfo->m_indices, GL_STATIC_DRAW);

	glVertexAttribPointer(POSITION_VB, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(POSITION_VB);

	glVertexAttribPointer(NORMAL_VB, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(NORMAL_VB);

	glVertexAttribPointer(TEXTURECOORD_VB, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(9 * sizeof(GLfloat)));
	glEnableVertexAttribArray(TEXTURECOORD_VB);

	glBindVertexArray(0);
}

Mesh::~Mesh()
{

}

void Mesh::SetupMesh()
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

	glVertexAttribPointer(NORMAL_VB, 3, GL_FLOAT, GL_FALSE, sizeof(Structs::Vertex), (GLvoid*)offsetof(Structs::Vertex, Normal));
	glEnableVertexAttribArray(NORMAL_VB);

	glVertexAttribPointer(TEXTURECOORD_VB, 2, GL_FLOAT, GL_FALSE, sizeof(Structs::Vertex), (GLvoid*)offsetof(Structs::Vertex, TexCoords));
	glEnableVertexAttribArray(TEXTURECOORD_VB);

	glBindVertexArray(0);
}

void Mesh::Draw()
{
	GLuint diffuseNr = 1;
	GLuint specularNr = 1;
	for (GLuint i = 0; i < textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i); // Activate proper texture unit before binding
		// Retrieve texture number (the N in diffuse_textureN)
		stringstream ss;
		string number;
		string name = textures[i].type;
		if (name == "texture_diffuse")
			ss << diffuseNr++; // Transfer GLuint to stream
		else if (name == "texture_specular")
			ss << specularNr++; // Transfer GLuint to stream
		number = ss.str();
		GLint matShineLoc = glGetUniformLocation(m_shaderProgram, ("material." + name + number).c_str());
		glUniform1f(matShineLoc, i);
		glBindTexture(GL_TEXTURE_2D, textures[i].id);
	}
	glActiveTexture(GL_TEXTURE0);

	// Draw mesh
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Mesh::Update()
{
	//texture->Update();
	
	glPolygonMode(GL_FRONT_AND_BACK, m_polygonMode);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, verticesInfo->m_verticesSize);
	//glDrawElements(GL_TRIANGLES, m_verticesInfo->m_indicesSize, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Mesh::ChangePolygonMode()
{
	m_polygonMode = m_polygonMode == GL_LINE ? GL_FILL : GL_LINE;
}