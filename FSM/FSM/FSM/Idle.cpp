#include "pch.h"
#include "Idle.h"
#include "Animation.h"
#include <iostream>
#include "Attack.h"
#include "Jumping.h"

using namespace std;

Idle::Idle()
{
	//Do animation
}


Idle::~Idle()
{
}

void Idle::jumping(Animation* a) {
	cout << "jumping" << endl;
	Jumping* jumping = new Jumping();
	a->SetCurrent(new Idle());
	delete(this);
}

void Idle::attack(Animation* a) {
	cout << "attack" << endl;
	Attack* attack = new Attack();	
	a->SetCurrent(new Idle());
	delete(this);
}
