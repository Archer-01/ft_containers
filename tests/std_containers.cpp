#include "tests.hpp"

int main()
{
	// Iterator traits
	{
		iterator_traits_vector<std::iterator_traits>();
		iterator_traits_int_ptr<std::iterator_traits>();
		iterator_traits_const_int_ptr<std::iterator_traits>();
	}
	return 0;
}
