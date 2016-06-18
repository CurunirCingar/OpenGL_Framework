#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <SDL\SDL.h>
#include <gl\glew.h>
#include "Camera.h"
#include "Graphics.h"
#include "Mesh.h"
#include "Model.h"
#include "Transform.h"
#include "Component.h"

#ifndef _GameObject_
#define  _GameObject_

class GameObject
{
public:
	GameObject();
	GameObject(string& objectName, string& shaderFilename, string& modelFilename);
	virtual ~GameObject();

	void Start();
	void Update();
	void ChangeDrawingMode();
	void CheckName();
	void SetCamera();

	void CreateShader(std::string& shaderFilename, Structs::Transform* transform);

	GLint id;
	string name;
	
	Shader* shader;
	Transform* transform;
	Model* model;
	Camera* camera;

	std::list<Component> Components;
};
#endif
