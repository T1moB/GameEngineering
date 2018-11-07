// Tester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <assert.h>
#include <vector>
#include <iterator>

using namespace std;

vector<int> numbers(6);
int main()
{
    cout << "Write 6 numbers between 1 and 46\n"; 

	char* tempChar; std::string s;
	std::getline(std::cin, s);
	std::istringstream is(s);
	std::vector<int> v((std::istream_iterator<int>(is)), std::istream_iterator<int>());
	for (int x : v) std::cout << x << ' ';
	std::cout << std::endl;

	assert(v.size() <= 6);
	for (int i = 0; i < v.size(); i++)
	{
		assert(v[i] > 0 && v[i] < 46);
		for (int j = 0; j < v.size(); j++)
		{
			if (i == j)
				continue;
			assert(v[i] != v[j]);
		}

	}
}
