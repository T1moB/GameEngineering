#pragma once
#include "System.h"
#include "Entity.h"
#include "SDL.h"
#include "SDL_Image.h"
#include <vector>

class RenderSystem
{
public:
	RenderSystem(SDL_Renderer* r);
	~RenderSystem();
	void AddEntity(Entity e) { entities.push_back(e); }
	void Update();
private:
	std::vector<Entity> entities;
	SDL_Renderer* rRenderer;
	SDL_Texture* player;
	SDL_Texture* alien;
	SDL_Texture * dog; 
	SDL_Texture* cat;
};

