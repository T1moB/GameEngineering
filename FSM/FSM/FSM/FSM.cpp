// FSM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SDL.h>
#include <thread>
#include <chrono>
#include "Animation.h"

using namespace std;

int main(int argc, char* args[])
{
	Animation fsm;
	int i = 0;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("FSM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	while (1) {
		if (i == 0) {
			fsm.jumping();
			this_thread::sleep_for(chrono::milliseconds(1000));
			i = 1;
		}
		else {
			fsm.attack();
			this_thread::sleep_for(chrono::milliseconds(1000));
			i = 0;
		}
	}
}

