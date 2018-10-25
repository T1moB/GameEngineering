#pragma once
#include "Command.h"
#include "Attack.h"
#include <iostream>


class FireCommand : public Command
{
public:
	virtual void Execute(Animation* a) { Fire(); }

private:
	void Fire() { std::cout << "Fire!" << std::endl; }
};