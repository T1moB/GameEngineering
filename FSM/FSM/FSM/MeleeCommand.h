#pragma once
#include "Command.h"
#include "Animation.h"
#include <iostream>

class MeleeCommand : public Command
{
public:
	//MeleeCommand(Animation* a);
	virtual void Execute(Animation* a) { Melee(a); }

private:
	void Melee(Animation* a);
};