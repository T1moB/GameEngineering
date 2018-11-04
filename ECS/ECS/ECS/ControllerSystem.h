#pragma once
#include "Entity.h"
class ControllerSystem
{
public:
	ControllerSystem();
	~ControllerSystem();
	void AddEntity(Entity e) { entities.push_back(e); }
	void Update();
private:
	std::vector<Entity> entities;
};

