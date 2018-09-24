#pragma once
#include "Character.h"
#include <iostream>

class Enemy : public Character
{
public:
	void draw() { std::cout << "This is a Enemy" << std::endl; }

private:

};