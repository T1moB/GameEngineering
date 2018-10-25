#include "InputHandler.h"
#include <Windows.h>
#include <iostream>
#include "Command.h"
#include "MeleeCommand.h"
#include "ShieldCommand.h"
#include "CouchCommand.h"
#include "FireCommand.h"
#include "JumpCommand.h"
#include "MacroCommand.h"
#include "SDL.h"
#include "SDL_keyboard.h"
#include "Idle.h"

bool isPressed = false;

Animation fsm;
MacroCommand macroCommand;
SDL_Event event;
SDL_KeyboardEvent *key;

InputHandler::InputHandler()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("FSM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	fsm.Init(renderer);
	//fsm.SetCurrent(new Idle(renderer));
	/* Enable Unicode translation */
	//SDL_EnableUNICODE(1);
}


InputHandler::~InputHandler()
{
}

void InputHandler::HandleInput() {
	Command* command;
	/* Poll for events */
	while (SDL_PollEvent(&event)) {

		switch (event.type) {
			/* Keyboard event */
			/* Pass the event data onto PrintKeyInfo() */
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			PrintKeyInfo(&event.key);
			key = &event.key;
			break;

			/* SDL_QUIT event (window close) */
		case SDL_QUIT:
			break;

		default:
			break;
		}

	}
	//if (key) {
		//if (SDL_GetKeyName(key->keysym.scancode) == "1") {
		if (GetKeyState('1') & 0x8000) {
			if (!isPressed) {
				command = new MeleeCommand;
				command->Execute(&fsm);
				macroCommand.Add(command);
				isPressed = true;
			}
		}
		else if (GetKeyState('2') & 0x8000) {
			if (!isPressed) {
				command = new ShieldCommand;
				command->Execute(&fsm);
				macroCommand.Add(command);
				isPressed = true;
			}
		}
		else if (GetKeyState('3') & 0x8000) {
			if (!isPressed) {
				command = new CrouchCommand;
				command->Execute(&fsm);
				macroCommand.Add(command);
				isPressed = true;
			}
		}
		else if (GetKeyState('4') & 0x8000) {
			if (!isPressed) {
				command = new FireCommand;
				command->Execute(&fsm);
				macroCommand.Add(command);
				isPressed = true;
			}
		}
		else if (GetKeyState('5') & 0x8000) {
			if (!isPressed) {
				command = new JumpCommand;
				command->Execute(&fsm);
				macroCommand.Add(command);
				isPressed = true;
			}
		}
		else if (GetKeyState(VK_CONTROL) && GetKeyState('A') & 0x8000) {
			if (!isPressed) {
				macroCommand.Execute(&fsm);
				isPressed = true;
			}
		}
		else if (GetKeyState(VK_CONTROL) && GetKeyState('X') & 0x8000) {
			if (!isPressed) {
				macroCommand.Redo(&fsm);
				isPressed = true;
			}
		}
		else if (GetKeyState(VK_CONTROL) && GetKeyState('Z') & 0x8000) {
			if (!isPressed) {
				macroCommand.Undo(&fsm);
				isPressed = true;
			}
		}
		else {
			isPressed = false;
		}
	//}
}


/* Print all information about a key event */
void InputHandler::PrintKeyInfo(SDL_KeyboardEvent *key) {
	/* Is it a release or a press? */
	if (key->type == SDL_KEYUP)
		printf("Release:- ");
	else
		printf("Press:- ");

	/* Print the hardware scancode first */
	printf("Scancode: 0x%02X", key->keysym.scancode);
	/* Print the name of the key */
	printf(", Name: %s", SDL_GetKeyName(key->keysym.sym));
	/* We want to print the unicode info, but we need to make */
	/* sure its a press event first (remember, release events */
	/* don't have unicode info                                */
	if (key->type == SDL_KEYDOWN) {
		/* If the Unicode value is less than 0x80 then the    */
		/* unicode value can be used to get a printable       */
		/* representation of the key, using (char)unicode.    */
		printf(", Unicode: ");
		if (key->keysym.scancode < 0x80 && key->keysym.scancode > 0) {
			printf("%c (0x%04X)", (char)key->keysym.scancode,
				key->keysym.scancode);
		}
		else {
			printf("? (0x%04X)", key->keysym.scancode);
		}
	}
	printf("\n");
	/* Print modifier info */
	//PrintModifiers(key->keysym.mod);
}