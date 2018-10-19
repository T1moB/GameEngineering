#include "pch.h"
#include "Attack.h"
#include "Animation.h"
#include "Idle.h"
#include <iostream>


Attack::Attack()
{
	//do animation
}


Attack::~Attack()
{
}

void Attack::idle(Animation* a) {
	std::cout << "From attack to idle" << std::endl;
	a->SetCurrent(new Idle());
	delete(this);
}