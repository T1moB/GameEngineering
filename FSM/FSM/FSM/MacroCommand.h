#pragma once
#include "Command.h"
#include "Animation.h"
#include "Attack.h"
#include <list>
class MacroCommand : public Command
{
public:
	MacroCommand();
	~MacroCommand();
	void Execute(Animation* a);
	void Add(Command* c);
	void Remove(Command* c);
	void Undo(Animation* a);
	void Redo(Animation* a);
private:
	std::list<Command*> commands;
};

