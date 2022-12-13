#pragma once

#include "algorithm.hpp"
#include "tests.hpp"
#include <vector>

template<typename T>
static bool myPredicate(const T& first, const T& second)
{
	return first == second;
}

void test_std_equal();
void test_ft_equal();
