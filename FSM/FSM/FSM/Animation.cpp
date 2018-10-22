#include "pch.h"
#include "Animation.h"
#include "Idle.h"
#include <SDL.h>
#include <SDL_image.h>


Animation::Animation()
{
	SDL_Window* window = SDL_CreateWindow("FSM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	current = new Idle(renderer);
}

Animation::~Animation()
{
}

void Animation::idle() {
	current->idle(this);
}

void Animation::jumping() {
	current->jumping(this);
}

void Animation::attack() {
	current->attack(this);
}
