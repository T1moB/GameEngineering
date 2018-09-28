#pragma once
#include "Command.h"
#include <iostream>


class FireCommand : public Command
{
public:
	virtual void Execute() { Fire(); }

private:
	void Fire() { std::cout << "Fire!" << std::endl; }
};