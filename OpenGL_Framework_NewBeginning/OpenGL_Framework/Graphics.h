#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

#include <SDL\SDL.h>
#include <gl\glew.h>
#include <glm\glm.hpp>

#include <assimp\scene.h>

#include "Structures.h"

#ifndef _Graphics_
#define  _Graphics_

class Graphics
{
public:
	static Graphics* instance()
	{
		if (!m_this)
		{
			m_this = new Graphics();
		}
		return m_this;
	}
	virtual ~Graphics();

	inline GLint GetNewId() { return objectsAmount++; }

	list<void*> GameObjects;
	list<void*> BlendedGameObjects;

	list<void*> lightSources;
	void* Sun;
	void* Skybox;
	void* Terrain;
	void* MainCamera;

	GLint width, height;

private:
	Graphics();
	static Graphics* m_this;
	GLint objectsAmount = 0;
};

inline void SetVec3Unif(GLint local, glm::vec3& vec)
{
	glUniform3f(local, vec.x, vec.y, vec.z);
};

namespace Structs
{
	struct Transform
	{
		glm::vec3 pos;
		glm::vec3 rot;
		glm::vec3 front;
	};

	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
	};

	struct Texture {
		GLuint id;
		string shaderName;
		GLuint type;
		aiString path;  // We store the path of the texture to compare with other textures
	};
};

#endif