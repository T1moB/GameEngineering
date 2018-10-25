#include "MacroCommand.h"
#include "Command.h"
#include "EmptyCommand.h"
#include "Animation.h"
#include <list>

using namespace std;

MacroCommand::MacroCommand()
{
	Command* emptyCommand = new EmptyCommand;
	commands.reverse();
	commands.push_front(emptyCommand);
}


MacroCommand::~MacroCommand()
{
}

void MacroCommand::Execute(Animation* a) {
	typedef std::list<Command> commandsList;
	for (auto ci = commands.begin(); ci != commands.end(); ++ci)
	{
		Command* com = *ci;
		com->Execute(a);
	}
}

void MacroCommand::Add(Command* c) {
	auto it = commands.end();
	commands.insert(it, c);
}

void MacroCommand::Remove(Command* c) {
	//commands.remove(c);
}

void MacroCommand::Redo(Animation* a) {
	if (commands.size() > 1) {
		commands.back()->Execute(a);
	}
}

void MacroCommand::Undo(Animation* a) {
	if (commands.size() > 1) {
		commands.back()->Execute(a);
		commands.pop_back();
	}
}
