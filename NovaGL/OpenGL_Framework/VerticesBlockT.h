#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include <SDL\SDL.h>
#include <gl\glew.h>
#include <glm\glm.hpp>

#ifndef _VerticesBlockT_
#define  _VerticesBlockT_
struct VertexT
{
	glm::vec3 pos;
	glm::vec3 norm;
	glm::vec3 col;
	glm::vec2 texCoord;
};

class VerticesBlockT
{
public:
	VerticesBlockT(const std::string& filename);
	~VerticesBlockT();

	VerticesBlockT* GetVerticesInfoFromFile(const std::string& verticesFilename);
	void SetVertices(std::string textBlock, GLuint linesAmount);
	void SetIndices(std::string textBlock, GLuint linesAmount);
	void SetTextures(std::string textBlock, GLuint linesAmount);

	enum FileParsingStagesT{
		START,
		VERTICES,
		INDICES,
		TEXTURES,
		END,
		ERROR
	};

	VertexT* m_vertices;
	GLuint m_verticesSize;
	GLuint* m_indices;
	GLuint m_indicesSize;

	std::string* m_texturesFilesArr;
	GLuint m_texturesFilesArrLen;
};
#endif