#pragma once
#include "Character.h"
#include <iostream>

class NPC : public Character
{
public:
	void draw() { std::cout << "This is a NPC" << std::endl; }

private:

};