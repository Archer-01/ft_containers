#include "tests.hpp"

int main()
{
	// Iterator traits
	{
		iterator_traits_vector<ft::iterator_traits>();
		iterator_traits_int_ptr<ft::iterator_traits>();
		iterator_traits_const_int_ptr<ft::iterator_traits>();
	}
	// Reverse Iterator
	{
		reverse_iterator_vector<ft::reverse_iterator>();
	}
	return 0;
}
