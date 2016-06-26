#include "Mesh.h"

Mesh::Mesh(vector<Structs::Vertex> vertices, vector<GLuint> indices, vector<Structs::Texture> textures, Shader* shader)
{
	this->shader = shader;

	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

	SetupMesh();
}

Mesh::~Mesh()
{

}

Shader* Mesh::CreateShader(std::string& shaderFilename, Structs::Transform* transform)
{
	switch (sdr::type[shaderFilename])
	{
	case sdr::Standard:
		return new StandardShader();
		break;

	case sdr::StandardBlended:
		return new StandardBlendedShader();
		break;

	case sdr::Light:
		return new LightShader(transform);
		break;

	case sdr::Reflective:
		return new ReflectiveShader();
		break;

	case sdr::Refractive:
		return new RefractiveShader();
		break;

	case sdr::Skybox:
		return new SkyboxShader();
		break;

	case sdr::Screen:
		return new ScreenShader();
		break;
	}
}

void Mesh::SetupMesh()
{
	polygonMode = GL_FILL;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Structs::Vertex), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

	if (shader->bindSettings == sdr::BIND_POS ||
		shader->bindSettings == sdr::BIND_POS_NORMAL ||
		shader->bindSettings == sdr::BIND_POS_TEX ||
		shader->bindSettings == sdr::BIND_POS_NORMAL_TEX)
	{
		glVertexAttribPointer(POSITION_VB, 3, GL_FLOAT, GL_FALSE, sizeof(Structs::Vertex), (GLvoid*)0);
		glEnableVertexAttribArray(POSITION_VB);
	}

	if (shader->bindSettings == sdr::BIND_POS_NORMAL ||
		shader->bindSettings == sdr::BIND_POS_NORMAL_TEX)
	{
		glVertexAttribPointer(NORMAL_VB, 3, GL_FLOAT, GL_FALSE, sizeof(Structs::Vertex), (GLvoid*)offsetof(Structs::Vertex, Normal));
		glEnableVertexAttribArray(NORMAL_VB);
	}

	if (shader->bindSettings == sdr::BIND_POS_TEX ||
		shader->bindSettings == sdr::BIND_POS_NORMAL_TEX)
	{
		glVertexAttribPointer(TEXTURECOORD_VB, 2, GL_FLOAT, GL_FALSE, sizeof(Structs::Vertex), (GLvoid*)offsetof(Structs::Vertex, TexCoords));
		glEnableVertexAttribArray(TEXTURECOORD_VB);
	}

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
		string name = textures[i].shaderName;
		if (name == "texture_diffuse")
			ss << diffuseNr++; // Transfer GLuint to stream
		else 
			if (name == "texture_specular")
				ss << specularNr++; // Transfer GLuint to stream
		number = ss.str();
		GLint matShineLoc = glGetUniformLocation(shader->GetProgramID(), ("material." + name + number).c_str());
		glUniform1f(matShineLoc, i);
		glBindTexture(textures[i].type, textures[i].id);
	}
	glActiveTexture(GL_TEXTURE0);
	
	// Draw mesh
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Mesh::ChangePolygonMode()
{
	polygonMode = polygonMode == GL_LINE ? GL_FILL : GL_LINE;
}

/*
// Old Mesh constructor 

Mesh::Mesh(const std::string& shaderFilename, const std::string& verticesFilename, GLuint shaderProgram)
{
	m_shaderProgram = shaderProgram;

	verticesInfo = new VerticesBlockT(verticesFilename);

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
*/