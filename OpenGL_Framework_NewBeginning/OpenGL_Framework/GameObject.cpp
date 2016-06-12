#include "GameObject.h"


GameObject::GameObject()
{

}

GameObject::GameObject(string& objectName, string& shaderFilename, string& modelFilename)
{
	id = Graphics::instance()->GetNewId();
	name = objectName;

	transform = new Transform();

	CreateShader(shaderFilename, &transform->transform);

	model = new Model("Res/" + modelFilename, shader->GetProgramID());

	transform->SetProgramID(shader->GetProgramID());
}

void GameObject::CreateShader(const std::string& shaderFilename, Structs::Transform* transform)
{
	if (!shaderFilename.compare("StandardShader"))
		shader = new StandardShader(shaderFilename);

	else if (!shaderFilename.compare("LightShader"))
		shader = new LightShader(shaderFilename, transform);
}

GameObject::~GameObject()
{
	delete transform;
}

void GameObject::Start()
{
	transform->Start();
}

void GameObject::Update()
{
	shader->Update();
	transform->Update();
	model->Draw();
}

void GameObject::ChangeDrawingMode()
{
	//mesh->ChangePolygonMode();
}

void GameObject::SetCamera()
{
	camera = new Camera(&transform->transform);
	Graphics::instance()->MainCamera = camera;
}
