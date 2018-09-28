#pragma once
#include "Command.h"
#include <iostream>


class EmptyCommand : public Command
{
public:
	virtual void Execute() { std::cout << "Nothing" << std::endl; }

};