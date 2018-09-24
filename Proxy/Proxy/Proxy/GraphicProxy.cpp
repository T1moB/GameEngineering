#include "stdafx.h"
#include "GraphicProxy.h"
#include "Graphic.h"
#include <iostream>

GraphicProxy::GraphicProxy()
{
	this->graphic = 0;
}


GraphicProxy::~GraphicProxy()
{
	if (graphic) delete graphic;
}

Graphic* GraphicProxy::GetInstance(void) {
	if (!graphic) graphic = new Graphic;
	return graphic;
}

void GraphicProxy::Draw(){
	GetInstance()->draw();
}
