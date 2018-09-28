#pragma once
#include "Command.h"
#include <iostream>


class CrouchCommand : public Command
{
public:
	virtual void Execute() { Crouch(); }

private:
	void Crouch() { std::cout << "Crouch" << std::endl; }
};