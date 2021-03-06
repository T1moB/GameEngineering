// Factory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include "CharacterFactory.h"
#include "Player.h"
#include "Enemy.h"
#include "NPC.h"
#include "Factory.h"
#include "Character.h"


int main()
{
	Factory* characterFac = new CharacterFactory;
	std::vector<Character*> characters;
	characters.push_back(characterFac->CreatePlayer());
	characters.push_back(characterFac->CreateEnemies());
	characters.push_back(characterFac->CreateNPC());

	for (int i = 0; i < characters.size(); i++)
	{
		characters[i]->draw();
	}

    return 0;
}

