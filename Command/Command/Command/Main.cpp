// Command.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "InputHandler.h"

using namespace std;

int main()
{	
	InputHandler* inputHandler = new InputHandler;
	cout << "Click 1, 2, 3, 4 or 5 to do an action" << endl;
	while (1)
	{
		inputHandler->HandleInput();
	};
    return 0;
}

