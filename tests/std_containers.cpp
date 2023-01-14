#include "test_utility.hpp"
#include "tests.hpp"

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
	// Utility
	{
		test_pair<std::pair>();
		test_std_make_pair();
	}
	// Vector
	{
		test_vector<std::vector>();
	}
	// Map
	{
		test_map<std::pair, std::map>(std::make_pair);
	}
	// Stack
	{
		test_stack<std::stack>();
	}
	// Set
	{
		test_set<std::set>();
	}
	return 0;
}
