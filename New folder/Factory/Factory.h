#pragma once
#include "Character.h"

class Factory
{
public:
	//Factory() {}
	//~Factory() {}
	virtual Character* CreatePlayer() = 0;
	virtual Character* CreateEnemies() = 0;
	virtual Character* CreateNPC() = 0;

private:

};