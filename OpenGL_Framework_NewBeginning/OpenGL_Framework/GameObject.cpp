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

void GameObject::CreateShader(std::string& shaderFilename, Structs::Transform* transform)
{
	switch (sdr::type[shaderFilename])
	{
	case sdr::Standard:
		shader = new StandardShader();
		Graphics::instance()->GameObjects.push_back((void*)this);
		break;

	case sdr::StandardBlended:
		shader = new StandardBlendedShader();
		Graphics::instance()->BlendedGameObjects.push_back((void*)this);
		break;

	case sdr::Light:
		shader = new LightShader(transform);
		Graphics::instance()->GameObjects.push_back((void*)this);
		break;
	}
}

GameObject::~GameObject()
{
	delete transform;
}

void GameObject::Start()
{
	CheckName();
	transform->Start();
}

void GameObject::CheckName()
{
	
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