#include "Application.h"
#include <iostream>
#include <iterator>
#include <sstream>



Application::Application()
{
}


Application::~Application()
{
}

std::vector<int> Application::AskInput(int amount) {
	std::cout << "Write " << amount << " numbers between 1 and 46\n";

	char* tempChar; std::string s;
	std::getline(std::cin, s);
	std::istringstream is(s);
	std::vector<int> v((std::istream_iterator<int>(is)), std::istream_iterator<int>());
	for (int x : v) std::cout << x << ' ';
	std::cout << std::endl;
	v.resize(amount);
	return v;
}
