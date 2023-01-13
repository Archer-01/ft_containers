#pragma once

#include "../utility.hpp"

template <typename T1, typename T2>
struct ft::pair
{
	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;

	pair();
	pair(const T1& first, const T2& second);
	template <typename U1, typename U2>
	pair(const pair<U1, U2>& rhs);

	pair& operator=(const pair& rhs);
};

namespace ft
{

	template <typename T1, typename T2>
	bool operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs);

	template <typename T1, typename T2>
	bool operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs);

	template <typename T1, typename T2>
	bool operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs);

	template <typename T1, typename T2>
	bool operator<=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs);

	template <typename T1, typename T2>
	bool operator>(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs);

	template <typename T1, typename T2>
	bool operator>=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs);

}; // namespace ft

#include "pair_impl.hpp"
