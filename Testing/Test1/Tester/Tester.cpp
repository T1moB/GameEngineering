// Tester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <assert.h>
#include <vector>
#include "../Application/Application.h"

int main()
{

	Application a;
	std::vector<int> numbers = a.AskInput(6);
	
	assert(numbers.size() <= 6);
	for (int i = 0; i < numbers.size(); i++)
	{
		assert(numbers[i] > 0 && numbers[i] < 46);
		for (int j = 0; j < numbers.size(); j++)
		{
			if (i != j)
				assert(numbers[i] != numbers[j]);
		}

	}
}
