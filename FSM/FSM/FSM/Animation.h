#pragma once
#include "SDL.h"
class Animation
{
	class State* current;
public:
	Animation();
	~Animation();
	void Init(SDL_Renderer* renderer);
	void SetCurrent(State* s) { current = s; }
	void idle();
	void jumping();
	void attack();
	void shielding();
};

