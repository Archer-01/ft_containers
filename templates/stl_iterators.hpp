#pragma once

#include <cstddef>
#include <iterator>

namespace ft
{

	template<typename T>
	class random_access_iterator;

	template<typename NodeType, typename T>
	class bidirectionnal_tree_iterator;

}; // namespace ft

#include "stl_iterators_internals/random_access_iterator.hpp"
#include "stl_iterators_internals/bidirectionnal_tree_iterator.hpp"
