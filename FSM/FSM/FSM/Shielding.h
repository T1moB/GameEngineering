#pragma once
#include "State.h"
#include "Animation.h"
#include <SDL.h>

class Shielding : public State
{
public:
	Shielding(SDL_Renderer* r);
	~Shielding();
	void idle(Animation* a);
};

