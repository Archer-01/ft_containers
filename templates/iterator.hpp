#pragma once

namespace ft
{

	template <typename Iterator>
	struct iterator_traits;

	template <typename T>
	struct iterator_traits<T*>;

	template <typename T>
	struct iterator_traits<const T*>;

	template <typename Iterator>
	class reverse_iterator;

}; // namespace ft

#include "iterator_internals/iterator_traits.hpp"
#include "iterator_internals/reverse_iterator.hpp"
