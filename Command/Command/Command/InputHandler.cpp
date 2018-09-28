#include "stdafx.h"
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

bool isPressed = false;

MacroCommand* macroCommand = new MacroCommand;
InputHandler::InputHandler()
{
}


InputHandler::~InputHandler()
{
}

void InputHandler::HandleInput() {
	Command* command;

	if (GetKeyState('1') & 0x8000) {
		if (!isPressed) {
			command = new MeleeCommand;
			command->Execute();
			macroCommand->Add(command);
			isPressed = true;
		}
	}
	else if (GetKeyState('2') & 0x8000) {
		if (!isPressed) {
			command = new ShieldCommand;
			command->Execute();
			macroCommand->Add(command);
			isPressed = true;
		}
	}
	else if (GetKeyState('3') & 0x8000) {
		if (!isPressed) {
			command = new CrouchCommand;
			command->Execute();
			macroCommand->Add(command);
			isPressed = true;
		}
	}
	else if (GetKeyState('4') & 0x8000) {
		if (!isPressed) {
			command = new FireCommand;
			command->Execute();
			macroCommand->Add(command);
			isPressed = true;
		}
	}
	else if (GetKeyState('5') & 0x8000) {
		if (!isPressed) {
			command = new JumpCommand;
			command->Execute();
			macroCommand->Add(command);
			isPressed = true;
		}
	}
	else if (GetKeyState(VK_CONTROL) && GetKeyState('A') & 0x8000) {
		if (!isPressed) {
			macroCommand->Execute();
			isPressed = true;
		}
	}
	else if (GetKeyState(VK_CONTROL) && GetKeyState('X') & 0x8000) {
		if (!isPressed) {
			macroCommand->Redo();
			isPressed = true;
		}
	}
	else if (GetKeyState(VK_CONTROL) && GetKeyState('Z') & 0x8000) {
		if (!isPressed) {
			macroCommand->Undo();
			isPressed = true;
		}
	}
	else {
		isPressed = false;
	}
}