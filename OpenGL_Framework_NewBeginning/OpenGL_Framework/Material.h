#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include <SDL\SDL.h>
#include <gl\glew.h>

#include "VerticesBlockT.h"
#include "Shader.h"
#include "StandardShader.h"
#include "LightShader.h"
#include "Texture.h"

#ifndef _Material_
#define  _Material_

class Material
{
public:
	Material(VerticesBlockT* verticesBlock, const std::string& shaderFilename);
	virtual ~Material();

	void Update();
	static Shader* CreateShader(const std::string& shaderFilename, Structs::Transform* transform);

	Texture* texture;
};
#endif
