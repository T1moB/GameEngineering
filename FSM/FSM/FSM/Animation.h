#pragma once
class Animation
{
	class State* current;
public:
	Animation();
	~Animation();
	void SetCurrent(State* s) { current = s; }
	void idle();
	void jumping();
	void attack();
};

