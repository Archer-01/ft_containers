#pragma once

namespace ft
{

	template<typename Iterator>
	struct iterator_traits;

	template<typename T>
	struct iterator_traits<T*>;

	template<typename T>
	struct iterator_traits<const T*>;

}; // namespace ft

#include "iterator_internals/iterator_traits.hpp"
