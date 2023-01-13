#pragma once

#include "../algorithm.hpp"

template <typename InputIterator1, typename InputIterator2>
bool ft::lexicographical_compare(
	InputIterator1 first1,
	InputIterator1 last1,
	InputIterator2 first2,
	InputIterator2 last2
)
{
	#pragma unroll
	while (first1 != last1 and first2 != last2)
	{
		if (*first1 < *first2)
		{
			return true;
		}
		if (*first2 < *first1)
		{
			return false;
		}
		++first1, ++first2;
	}
	return (first1 == last1) and (first2 != last2);
}

template <
	typename InputIterator1,
	typename InputIterator2,
	typename Compare
>
bool ft::lexicographical_compare(
	InputIterator1 first1,
	InputIterator1 last1,
	InputIterator2 first2,
	InputIterator2 last2,
	Compare compare
)
{
	#pragma unroll
	while (first1 != last1 and first2 != last2)
	{
		if (compare(*first1, *first2))
		{
			return true;
		}
		if (compare(*first2, *first1))
		{
			return false;
		}
		++first1, ++first2;
	}
	return (first1 == last1) and (first2 != last2);
}
