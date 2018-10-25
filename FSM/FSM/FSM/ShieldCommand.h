#pragma once
#include "Command.h"
#include "Attack.h"
#include <iostream>


class ShieldCommand : public Command
{
public:
	virtual void Execute(Animation* a) { Shield(a); }

private:
	void Shield(Animation* a) { a->shielding(); }
};