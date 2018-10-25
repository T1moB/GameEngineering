#pragma once
#include "Command.h"
#include "Attack.h"
#include <iostream>


class EmptyCommand : public Command
{
public:
	virtual void Execute(Animation* a) { std::cout << "Nothing" << std::endl; }

};