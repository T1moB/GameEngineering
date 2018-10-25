#pragma once
#include "State.h"
#include "Animation.h"
#include <SDL.h>
#include <SDL_image.h>

class Idle : public State
{
public:
	Idle(SDL_Renderer* r);
	~Idle();
	void jumping(Animation* a);
	void attack(Animation* a);
	void shielding(Animation* a);
};

