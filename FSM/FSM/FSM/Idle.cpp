#include "pch.h"
#include "Idle.h"
#include "Animation.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Attack.h"
#include "Jumping.h"

using namespace std;

SDL_Window* window /*= SDL_CreateWindow("FSM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_OPENGL)*/;
SDL_Renderer* renderer /*= SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)*/;

#define frames 10
SDL_Surface* surface;
SDL_Texture* textures[frames];

Idle::Idle(SDL_Renderer* r)
{
	renderer = r;
	IMG_Init(IMG_INIT_PNG); 
	for (int i = 0; i < 4; i++)
	{
		for (int i = 0; i < frames; i++)
		{
			int count = i;
			char name[30];
			sprintf_s(name, "%d", count);
			char path[64] = "Data/BlueKnight_entity_000_idle_00";
			strcat_s(path, name);
			strcat_s(path, ".png");
			//path += ".png";
			//const char* path = "BlueKnight_entity_000_jump_00" + number;
			//path += number;
			surface = IMG_Load(path);
			if (surface == NULL) { printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError()); }
			SDL_Texture* tex = SDL_CreateTextureFromSurface(r, surface);
			textures[i] = tex;
			//textures.insert(tex, textures.end());
		}
		for (int i = 0; i < frames; i++)
		{
			SDL_RenderClear(r);
			SDL_RenderCopy(r, textures[i], NULL, NULL);
			SDL_RenderPresent(r);
			if (i == frames) { i = -1; }
		}
	}
	//Do animation
}


Idle::~Idle()
{
	//IMG_Quit();
}

void Idle::jumping(Animation* a) {
	cout << "jumping" << endl;
	Jumping* jumping = new Jumping(renderer);
	a->SetCurrent(new Idle(renderer));
	delete(this);
}

void Idle::attack(Animation* a) {
	cout << "attack" << endl;
	Attack* attack = new Attack(renderer);	
	a->SetCurrent(new Idle(renderer));
	delete(this);
}
