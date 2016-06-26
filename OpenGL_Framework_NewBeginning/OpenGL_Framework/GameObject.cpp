#include "GameObject.h"


GameObject::GameObject()
{

}

GameObject::GameObject(string& objectName, string& shaderFilename, string& modelFilename)
{
	id = Graphics::instance()->GetNewId();
	name = objectName;

	transform = new Transform();
	
	shader = Mesh::CreateShader(shaderFilename, &transform->transform);

	if (shader->type == sdr::StandardBlended)
		Graphics::instance()->BlendedGameObjects.push_back((void*)this);
	else
		Graphics::instance()->GameObjects.push_back((void*)this);

	model = new Model("Res/" + modelFilename, shader);

	transform->SetProgramID(shader->GetProgramID());
}

GameObject::~GameObject()
{
	delete transform;
}

void GameObject::Start()
{
	transform->Start();
}

void GameObject::SetCamera()
{
	//transform->SetPosition(glm::vec3(0,0,0));
	camera = new Camera(&transform->transform);
	Graphics::instance()->MainCamera = camera;
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