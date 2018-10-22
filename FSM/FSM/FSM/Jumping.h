#pragma once
#include "State.h"
#include "Animation.h"
#include <SDL.h>


class Jumping : public State
{
public:
	Jumping(SDL_Renderer* r);
	~Jumping();
	void idle(Animation* a);
};

