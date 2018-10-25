#pragma once
#include "Component.h"
#include <vector>

class Entity
{
	int id;
public:
	Entity() {};
	void AddComponent(Component c) { components.push_back(c); }
	void RemoveComponent(Component c) {/*TBI*/}
	std::vector<Component> GetComponents() { return components; }
	std::vector<Component> GetComponent(Component c) { 
		for (int i = 0; i < components.size(); i++)
		{
			//if(components[i] == c)
		}
	}
	~Entity();

private:
	std::vector<Component> components;
};