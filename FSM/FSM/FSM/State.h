#pragma once
#include <iostream>
#include "Animation.h"

using namespace std;
class State
{
public:
	virtual void idle(Animation* a) { cout << "state::idle" << endl; }
	virtual void jumping(Animation* a) { cout << "state::jumping" << endl; }
	virtual void attack(Animation* a) { cout << "state::attack" << endl; }
};