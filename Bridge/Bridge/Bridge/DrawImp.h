#pragma once
#include "DrawApi.h"
#include <iostream>

class DrawImp : public DrawApi
{
public:
	void draw() { std::cout << "Draw Api" << std::endl; }

private:

};