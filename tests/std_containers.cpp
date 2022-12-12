#include "tests.hpp"

int main()
{
	// Iterator traits
	{
		iterator_traits_vector<std::iterator_traits>();
		iterator_traits_int_ptr<std::iterator_traits>();
		iterator_traits_const_int_ptr<std::iterator_traits>();
	}
	// Reverse Iterator
	{
		reverse_iterator_vector<std::reverse_iterator>();
	}
	return 0;
}
