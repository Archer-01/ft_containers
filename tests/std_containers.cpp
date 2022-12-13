#include "test_algorithm.hpp"
#include "tests.hpp"
#include <algorithm.hpp>

int main()
{
	// Iterator traits
	{
		test_iterator_traits_vector<std::iterator_traits>();
		test_iterator_traits_int_ptr<std::iterator_traits>();
		test_iterator_traits_const_int_ptr<std::iterator_traits>();
	}
	// Reverse Iterator
	{
		test_reverse_iterator_vector<std::reverse_iterator>();
	}
	// Type traits
	{
		test_enable_if<std::enable_if>();
		test_is_integral<std::is_integral>();
	}
	// Algorithm
	{
		test_std_equal();
		test_std_lexicographical_compare();
	}
	return 0;
}
