#pragma once
#include "Entity.h"
#include "System.h"

class AISystem : public System
{
public:
	AISystem();
	~AISystem();
	void Update();
private:
};

