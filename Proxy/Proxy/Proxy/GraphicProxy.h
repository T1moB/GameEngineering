#pragma once
#ifndef GRAPHIC_PROXY_H
#define GRAPHIC_PROXY_H

#include "IGraphic.h"
#include "Graphic.h"

class GraphicProxy : public IGraphic
{
public:
	GraphicProxy();
	~GraphicProxy();
	void Draw();
private:
	Graphic* graphic;
	Graphic* GetInstance(void);
};

#endif