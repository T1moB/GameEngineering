#pragma once
#include "Component.h"
#include <vector>

class PositionComponent : public Component
{
public:
	PositionComponent(float xPos, float yPos) : x(xPos), y(yPos), position(x, y){}
	std::vector<float> GetPosition() { return position; }
	float GetXPosition() { return x; }
	float GetYPosition() { return y; }
	void SetPosition(std::vector<float> pos) { position = pos; }
	void SetXPosition(float xPos) { x = xPos; }
	void SetYPosition(float yPos) { y = yPos; }
	~PositionComponent();

private:
	float x, y;
	std::vector<float> position;
};
