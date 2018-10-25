#pragma once
#include "SDL.h"
class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	void HandleInput();

	void PrintKeyInfo(SDL_KeyboardEvent *key);
	//void PrintModifiers(SDLMod mod);
};

