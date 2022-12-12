#pragma once

namespace ft
{

	template <bool Cond, typename T = void>
	struct enable_if;

	template <typename T>
	struct is_integral;

}; // namespace ft

#include "type_traits_internals/enable_if.hpp"
#include "type_traits_internals/is_integral.hpp"
