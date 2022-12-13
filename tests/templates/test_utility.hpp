#pragma once

#include "utility.hpp"
#include <cassert>
#include <utility>

template <template <typename T1, typename T2> class Pair>
void test_pair()
{
	Pair<char, short> pair1('a', 97);
	Pair<char, short> pair2('b', 98);
	Pair<char, short> pair3(pair2);
	Pair<char, short> pair4;

	pair3 = pair1;
	assert(pair1 == pair3);
	assert(pair1 != pair2);
	assert(pair1 < pair2);
}

void test_std_make_pair();
void test_ft_make_pair();
