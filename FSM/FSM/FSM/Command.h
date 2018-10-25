#pragma once
#include "Attack.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void Execute(Animation* a) = 0;
	//virtual void Undo() = 0;

protected:
	Command() {}
};