#pragma once

namespace ft
{

	template <typename T1, typename T2>
	struct pair;

	template <typename T1, typename T2>
	ft::pair<T1, T2> make_pair(T1 first, T2 second);

}; // namespace ft

#include "utility_internals/pair.hpp"
