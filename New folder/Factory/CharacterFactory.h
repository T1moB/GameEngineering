#pragma once
#include "Factory.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "NPC.h"

class CharacterFactory : public Factory
{
public:
	Character* CreatePlayer() { return new Player; }
	Character* CreateEnemies() { return new Enemy; }
	Character* CreateNPC() { return new NPC; }

private:

};