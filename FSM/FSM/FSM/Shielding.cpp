#include "pch.h"
#include "Shielding.h"
#include "Animation.h"
#include "Idle.h"
#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

SDL_Renderer* sR;
#define frames 9
SDL_Surface* sSurface;

Shielding::Shielding(SDL_Renderer* r)
{
	SDL_Texture* sTextures [frames];
	for (int i = 0; i < frames; i++)
	{
		int count = i;
		char name[30];
		sprintf_s(name, "%d", count);
		char path[64] = "Data/BlueKnight_entity_000_dead front_00";
		strcat_s(path, name);
		strcat_s(path, ".png");
		//path += ".png";
		//const char* path = "BlueKnight_entity_000_jump_00" + number;
		//path += number;
		sSurface = IMG_Load(path);
		if (sSurface == NULL) { printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError()); }
		SDL_Texture* tex = SDL_CreateTextureFromSurface(r, sSurface);
		sTextures[i] = tex;
		sR = r;
		//textures.insert(tex, textures.end());
	}
	for (int i = 0; i < 4; i++)
	{
		for (int i = 0; i < frames; i++)
		{
			SDL_RenderClear(r);
			SDL_RenderCopy(r, sTextures[i], NULL, NULL);
			SDL_RenderPresent(r);
			if (i == frames) { i = -1; }
		}
	}
	//do animation
}


Shielding::~Shielding()
{
}

void Shielding::idle(Animation* a) {
	std::cout << "From jumping to idle" << std::endl;
	a->SetCurrent(new Idle(sR));
	delete(this);
}