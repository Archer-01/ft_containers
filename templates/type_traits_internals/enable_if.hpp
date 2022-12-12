#pragma once

#include "type_traits.hpp"

template <bool Cond, typename T>
struct ft::enable_if {};

template <typename T>
struct ft::enable_if<true, T>
{
	typedef T type;
};
