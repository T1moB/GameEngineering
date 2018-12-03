#pragma once
#include <vector>
class Application
{
public:
	Application();
	~Application();
	std::vector<int>AskInput(int amount);
	bool Test(std::vector<int>);
};

