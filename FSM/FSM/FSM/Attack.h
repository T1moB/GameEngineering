#pragma once
#include "State.h"
#include "Animation.h"
#include <SDL.h>

class Attack : public State
{
public:
	Attack(SDL_Renderer* r);
	~Attack();
	void idle(Animation* a);
};

