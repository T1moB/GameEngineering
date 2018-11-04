#pragma once
#include "System.h"
#include "Entity.h"
#include <vector>

class HealthSystem
{
public:
	HealthSystem();
	~HealthSystem();
	void AddEntity(Entity e) { entities.push_back(e); }
	void Update();
private:
	std::vector<Entity> entities;
};

