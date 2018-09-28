#include "stdafx.h"
#include "MacroCommand.h"
#include "Command.h"
#include "EmptyCommand.h"
#include <list>
#include <iostream>

using namespace std;

MacroCommand::MacroCommand()
{
	Command* emptyCommand = new EmptyCommand;
	commands = new std::list<Command*>{ emptyCommand };
}


MacroCommand::~MacroCommand()
{
}

void MacroCommand::Execute() {
	typedef list<Command> commandsList;
	//for (IntegerList::const_iterator ci = intList.begin(); ci != intList.end(); ++ci)
	for(auto ci = commands->begin(); ci != commands->end(); ++ci)
	{
		Command* com = *ci;
		com->Execute();
	}
}

void MacroCommand::Add(Command* c) {
	auto it = commands->end();
	commands->insert(it , c);
}

void MacroCommand::Remove(Command* c) {
	commands->remove(c);
}

void MacroCommand::Redo() {
	if (commands->size() > 1) {
		commands->back()->Execute();
	}
}

void MacroCommand::Undo() {
	if (commands->size() > 1) {
		commands->back()->Execute();
		commands->pop_back();
	}
}
