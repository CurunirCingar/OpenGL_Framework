#pragma once

#ifndef _Component_
#define  _Component_
class Component
{
public:
	enum ComponentType
	{
		Light,
	};

	Component();
	virtual ~Component();
};
#endif

