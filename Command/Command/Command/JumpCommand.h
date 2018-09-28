#pragma once
#include "Command.h"
#include <iostream>

class JumpCommand : public Command
{
public:
	virtual void Execute() { Jump(); }


private:
	void Jump() { std::cout << "Jump!" << std::endl; }
};
