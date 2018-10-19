#pragma once
#include "State.h"
#include "Animation.h"

class Attack : public State
{
public:
	Attack();
	~Attack();
	void idle(Animation* a);
};

