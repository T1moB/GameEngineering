#include "pch.h"
#include "Jumping.h"
#include "Animation.h"
#include "Idle.h"
#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

SDL_Renderer* jR;
#define frames 9
SDL_Surface* jSurface;

Jumping::Jumping(SDL_Renderer* r)
{
	SDL_Texture* jTextures[frames];
		for (int i = 0; i < frames; i++)
		{
			int count = i;
			char name[30];
			sprintf_s(name, "%d", count);
			char path[64] = "Data/BlueKnight_entity_000_jump_00";
			strcat_s(path, name);
			strcat_s(path, ".png");
			//path += ".png";
			//const char* path = "BlueKnight_entity_000_jump_00" + number;
			//path += number;
			jSurface = IMG_Load(path);
			if (jSurface == NULL) { printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError()); }
			SDL_Texture* tex = SDL_CreateTextureFromSurface(r, jSurface);
			jTextures[i] = tex;
			jR = r;
			//textures.insert(tex, textures.end());
		}
		for (int i = 0; i < 4; i++)
		{
			for (int i = 0; i < frames; i++)
			{
				SDL_RenderClear(r);
				SDL_RenderCopy(r, jTextures[i], NULL, NULL);
				SDL_RenderPresent(r);
				if (i == frames) { i = -1; }
			}
		}
	//do animation
}


Jumping::~Jumping()
{
}

void Jumping::idle(Animation* a) {
	std::cout << "From jumping to idle" << std::endl;
	a->SetCurrent(new Idle(jR));
	delete(this);
}