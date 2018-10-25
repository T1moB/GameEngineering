#include "pch.h"
#include "Animation.h"
#include "Idle.h"
#include <SDL.h>
#include <SDL_image.h>


Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::Init(SDL_Renderer* renderer) {

	current = new Idle(renderer);
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

void Animation::shielding() {
	current->shielding(this);
}
