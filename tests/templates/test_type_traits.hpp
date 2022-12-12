#pragma once

#include "tests.hpp"
#include "type_traits.hpp"
#include <cassert>
#include <list>

template <template <bool Cond, typename T = void> class EnableIf>
void test_enable_if()
{
	assert(typeid(typename EnableIf<true, int>::type) == typeid(int));
	// The following test would not compile
	// assert(typeid(EnableIf<false, int>::type) == typeid(void));
}

template <template <typename T> class IsIntegral>
void test_is_integral()
{
	assert(IsIntegral<wchar_t>::value == true);
	assert(IsIntegral<const bool>::value == true);
	assert(IsIntegral<volatile short>::value == true);
	assert(IsIntegral<const volatile int>::value == true);
	assert(IsIntegral<double>::value == false);
	assert(IsIntegral<std::list<float> >::value == false);
	assert(IsIntegral<volatile std::list<int> >::value == false);
}
