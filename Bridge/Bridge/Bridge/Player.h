#pragma once
#include "DrawApi.h"
#include "Character.h"

class Player : public Character
{
public:
	Player(DrawApi* api) { this->api = api; }
	void draw() { api->draw(); }

private:
	DrawApi * api;
};