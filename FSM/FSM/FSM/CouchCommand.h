#pragma once
#include "Command.h"
#include "Attack.h"
#include <iostream>


class CrouchCommand : public Command
{
public:
	virtual void Execute(Animation* a) { Crouch(); }

private:
	void Crouch() { std::cout << "Crouch" << std::endl; }
};