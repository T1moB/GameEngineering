#pragma once
#ifndef GRAHPIC_H
#define GRAHPIC_H

#include "IGraphic.h"
#include <iostream>

class Graphic : public IGraphic
{
public:
	Graphic();
	~Graphic();
	void draw() { std::cout << "Drawing graphic object" << std::endl; }
};
#endif