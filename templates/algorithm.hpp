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

}; // namespace ft

#include "algorithm_internals/equal.hpp"
