#pragma once

#include "iterator.hpp"
#include "tests.hpp"
#include <vector>

template <template <typename Iterator> class IteratorTraits>
void test_iterator_traits_vector()
{
	typedef IteratorTraits<std::vector<int>::iterator> traits;

	assert(typeid(typename traits::difference_type) ==
		   typeid(std::vector<int>::iterator::difference_type));
	assert(typeid(typename traits::value_type) == typeid(int));
	assert(typeid(typename traits::pointer) == typeid(int *));
	assert(typeid(typename traits::reference) == typeid(int &));
	assert(typeid(typename traits::iterator_category) ==
		   typeid(std::random_access_iterator_tag));
}

template <template <typename Iterator> class IteratorTraits>
void test_iterator_traits_int_ptr()
{
	typedef IteratorTraits<int *> traits;

	assert(typeid(typename traits::difference_type) == typeid(std::ptrdiff_t));
	assert(typeid(typename traits::value_type) == typeid(int));
	assert(typeid(typename traits::pointer) == typeid(int *));
	assert(typeid(typename traits::reference) == typeid(int &));
	assert(typeid(typename traits::iterator_category) ==
		   typeid(std::random_access_iterator_tag));
}

template <template <typename Iterator> class IteratorTraits>
void test_iterator_traits_const_int_ptr()
{
	typedef IteratorTraits<const int *> traits;

	assert(typeid(typename traits::difference_type) == typeid(std::ptrdiff_t));
	assert(typeid(typename traits::value_type) == typeid(int));
	assert(typeid(typename traits::pointer) == typeid(const int *));
	assert(typeid(typename traits::reference) == typeid(const int &));
	assert(typeid(typename traits::iterator_category) ==
		   typeid(std::random_access_iterator_tag));
}
