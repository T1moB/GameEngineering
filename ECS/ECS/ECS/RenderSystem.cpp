#include "RenderSystem.h"
#include "PositionComponent.h"
#include "RenderComponent.h"
#include "RenderSystem.h"
#include "SDL.h"
#include <iostream>



RenderSystem::RenderSystem(SDL_Renderer* r) : rRenderer(r)
{
	SDL_Surface* surface;

	surface = IMG_Load("Data/player.png");
	player = SDL_CreateTextureFromSurface(r, surface);

	surface = IMG_Load("Data/alien.png");
	alien = SDL_CreateTextureFromSurface(r, surface);

	surface = IMG_Load("Data/dog.png");
	dog = SDL_CreateTextureFromSurface(r, surface);

	surface = IMG_Load("Data/cat.png");
	cat = SDL_CreateTextureFromSurface(r, surface);
}


RenderSystem::~RenderSystem()
{
}

void RenderSystem::Update() {


	SDL_RenderClear(rRenderer);

	SDL_Rect* texPos = new SDL_Rect();
	SDL_Texture* tex;
	texPos->h = 64;
	texPos->w = 64;
	for (int i = 0; i < entities.size(); i++)
	{
		texPos->x = entities[i].getComponent<PositionComponent>(Component::Type::Position)->GetXPosition();
		texPos->y = entities[i].getComponent<PositionComponent>(Component::Type::Position)->GetYPosition();
		tex = entities[i].getComponent<RenderComponent>(Component::Type::Render)->GetTexture();
		SDL_RenderCopy(rRenderer, tex, NULL, texPos);
	}
	SDL_RenderPresent(rRenderer);
}
