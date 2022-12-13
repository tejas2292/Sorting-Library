#include "RandStringGenerator.h"
#include <iostream>
#include <cstdlib>
#include <random>
using namespace::std;

string RandStringGenerator::random_string(size_t length)
{
	const string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(0, characters.size() - 1);

	string random_string;

	for (size_t i = 0; i < length; ++i)
	{
		random_string += characters[distribution(generator)];
	}

	return random_string;
}
