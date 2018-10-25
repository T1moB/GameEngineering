#include "pch.h"
#include "Attack.h"
#include "Animation.h"
#include "Idle.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

SDL_Renderer* _r;
#define frames 10
SDL_Surface* _surface;

Attack::Attack(SDL_Renderer* r)
{
	SDL_Texture* _textures[frames];
		for (int i = 0; i < frames; i++)
		{
			int count = i;
			char name[30];
			sprintf_s(name, "%d", count);
			char path[64] = "Data/BlueKnight_entity_000_basic attack 1_00";
			strcat_s(path, name);
			strcat_s(path, ".png");
			//path += ".png";
			//const char* path = "BlueKnight_entity_000_jump_00" + number;
			//path += number;
			_surface = IMG_Load(path);
			if (_surface == NULL) { printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError()); }
			SDL_Texture* tex = SDL_CreateTextureFromSurface(r, _surface);
			_textures[i] = tex;
			_r = r;
			//textures.insert(tex, textures.end());
		}
		for (int i = 0; i < 4; i++)
		{
			for (int i = 0; i < frames; i++)
			{
				SDL_RenderClear(r);
				SDL_RenderCopy(r, _textures[i], NULL, NULL);
				SDL_RenderPresent(r);
				if (i == frames) { i = -1; }
			}
		}
	//do animation
}


Attack::~Attack()
{
}

void Attack::idle(Animation* a) {
	std::cout << "From attack to idle" << std::endl;
	a->SetCurrent(new Idle(_r));
	delete(this);
}