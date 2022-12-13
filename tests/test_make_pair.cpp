#include "test_utility.hpp"

void test_std_make_pair()
{
	std::pair<char, short> pair1;

	pair1 = std::make_pair<char, short>('c', 99);
	assert(pair1.first == 'c');
	assert(pair1.second == 99);
}

void test_ft_make_pair()
{
	ft::pair<char, short> pair1;

	pair1 = ft::make_pair<char, short>('c', 99);
	assert(pair1.first == 'c');
	assert(pair1.second == 99);
}
