#include "Material.h"

Material::Material(VerticesBlockT* verticesBlock, const std::string& shaderFilename)
{
	
}

Material::~Material()
{
}

void Material::Update()
{
	texture->Update();
}

