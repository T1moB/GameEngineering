// Bridge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DrawApi.h"
#include "DrawImp.h"
#include "Character.h"
#include "Player.h"


int main()
{
	DrawApi* api = new DrawImp();
	Character* player = new Player(api);
	player->draw();

    return 0;
}

