#pragma once
#include "Command.h"
#include <iostream>

class MeleeCommand : public Command
{
public:
	virtual void Execute() { Melee(); }

private:
	void Melee() { std::cout << "Melee!" << std::endl; }
};