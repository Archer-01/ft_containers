#pragma once

#include "iterator.hpp"
#include "tests.hpp"

template <template <typename Iterator> class ReverseIterator>
void test_reverse_iterator_vector()
{
	typedef ReverseIterator<std::vector<int>::iterator> reverse_iterator;

	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(&arr[0], &arr[5]);
	reverse_iterator rit(vec.end());

	assert(*rit == 5);
	assert(rit[3] == 2);
	++rit;
	assert(*rit == 4);
	--rit;
	assert(*rit == 5);
	rit  += 4;
	assert(*rit == 1);
	assert(rit == reverse_iterator(vec.begin() + 1));
	assert(rit != reverse_iterator(vec.end()));
	assert(reverse_iterator(vec.begin()) > reverse_iterator(vec.end()));
}
