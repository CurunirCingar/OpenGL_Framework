#pragma once
#include "Transform.h"

class SkyboxTransform : public Transform
{
public:
	SkyboxTransform();
	~SkyboxTransform();

	void Update();
};

