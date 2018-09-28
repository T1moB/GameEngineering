#pragma once
#include "Command.h"
#include <list>

class MacroCommand : public Command
{
public:
	MacroCommand();
	virtual ~MacroCommand();
	virtual void Add(Command*);
	virtual void Remove(Command*);
	virtual void Undo();
	virtual void Redo();
	virtual void Execute();

private:
	std::list<Command*>* commands;
};
