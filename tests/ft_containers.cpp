#include "tests.hpp"

int main()
{
	// Iterator traits
	{
		iterator_traits_vector<ft::iterator_traits>();
		iterator_traits_int_ptr<ft::iterator_traits>();
		iterator_traits_const_int_ptr<ft::iterator_traits>();
	}
	return 0;
}
