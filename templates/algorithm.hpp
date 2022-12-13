#pragma once

namespace ft
{

	template <typename InputIterator1, typename InputIterator2>
	bool equal(
		InputIterator1 first1,
		InputIterator1 last1,
		InputIterator2 first2
	);

	template <
		typename InputIterator1,
		typename InputIterator2,
		typename BinaryPredicate
	>
	bool equal(
		InputIterator1 first1,
		InputIterator1 last1,
		InputIterator2 first2,
		BinaryPredicate predicate
	);

	template <typename InputIterator1, typename InputIterator2>
	bool lexicographical_compare(
		InputIterator1 first1,
		InputIterator1 last1,
		InputIterator2 first2,
		InputIterator2 last2
	);

	template <
		typename InputIterator1,
		typename InputIterator2,
		typename Compare
	>
	bool lexicographical_compare(
		InputIterator1 first1,
		InputIterator1 last1,
		InputIterator2 first2,
		InputIterator2 last2,
		Compare compare
	);

}; // namespace ft

#include "algorithm_internals/equal.hpp"
#include "algorithm_internals/lexicographical_compare.hpp"
