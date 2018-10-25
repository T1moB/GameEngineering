#pragma once
#include "Command.h"
#include "Attack.h"
#include <iostream>

class JumpCommand : public Command
{
public:
	virtual void Execute(Animation* a) { Jump(a); }


private:
	void Jump(Animation* a);
};
