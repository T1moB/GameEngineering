#pragma once
#include "Character.h"
#include <iostream>

class Player : public Character
{
public:
	void draw() { std::cout << "This is a player" << std::endl; }

private:

};