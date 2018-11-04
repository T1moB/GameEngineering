#pragma once
#include "Entity.h"
class AISystem
{
public:
	AISystem();
	~AISystem();
	void AddEntity(Entity e) { entities.push_back(e); }
	void Update();
private:
	std::vector<Entity> entities;
};

