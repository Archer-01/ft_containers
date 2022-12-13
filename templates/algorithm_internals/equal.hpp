#pragma once

#include "algorithm.hpp"
#include <algorithm>

template <typename InputIterator1, typename InputIterator2>
bool ft::equal(
	InputIterator1 first1,
	InputIterator1 last1,
	InputIterator2 first2
)
{
	#pragma unroll
	while (first1 != last1)
	{
		if (not (*first1 == *first2))
		{
			return false;
		}
		++first1, ++first2;
	}
	return true;
}

template <
	typename InputIterator1,
	typename InputIterator2,
	typename BinaryPredicate
>
bool ft::equal(
	InputIterator1 first1,
	InputIterator1 last1,
	InputIterator2 first2,
	BinaryPredicate predicate
)
{
	#pragma unroll
	while (first1 != last1)
	{
		if (not predicate(*first1, *first2))
		{
			return false;
		}
		++first1, ++first2;
	}
	return true;
}
