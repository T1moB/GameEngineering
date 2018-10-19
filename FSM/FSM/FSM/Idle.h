#pragma once
#include "State.h"
#include "Animation.h"

class Idle : public State
{
public:
	Idle();
	~Idle();
	void jumping(Animation* a);
	void attack(Animation* a);
};

