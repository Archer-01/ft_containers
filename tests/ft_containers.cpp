#include "tests.hpp"

int main()
{
	// Iterator traits
	{
		test_iterator_traits_vector<ft::iterator_traits>();
		test_iterator_traits_int_ptr<ft::iterator_traits>();
		test_iterator_traits_const_int_ptr<ft::iterator_traits>();
	}
	// Reverse Iterator
	{
		test_reverse_iterator_vector<ft::reverse_iterator>();
	}
	// Type traits
	{
		test_enable_if<ft::enable_if>();
		test_is_integral<ft::is_integral>();
	}
	return 0;
}
