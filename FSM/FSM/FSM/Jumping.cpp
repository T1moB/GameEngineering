#include "pch.h"
#include "Jumping.h"
#include "Animation.h"
#include "Idle.h"
#include <iostream>


Jumping::Jumping()
{
	//do animation
}


Jumping::~Jumping()
{
}

void Jumping::idle(Animation* a) {
	std::cout << "From jumping to idle" << std::endl;
	a->SetCurrent(new Idle());
	delete(this);
}