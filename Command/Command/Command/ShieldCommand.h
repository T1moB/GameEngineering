#pragma once
#include "Command.h"
#include <iostream>


class ShieldCommand : public Command
{
public:
	virtual void Execute() { Shield(); }

private:
	void Shield() { std::cout << "Shield!" << std::endl; }
};