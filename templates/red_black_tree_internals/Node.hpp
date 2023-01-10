#pragma once

#include "red_black_tree.hpp"
#include <cstddef>

template <typename T, typename Allocator>
struct ft::Node
{
	/**
	 * @def Typedefs
	 *
	 */
	typedef T value_type;
	typedef Allocator allocator_type;

	/**
	 * @defgroup Attributes
	 *
	 */
	value_type value;
	Node *left;
	Node *right;
	Node *parent;
	NodeColor color;
	NodeSide side;

	/**
	 * @defgroup Constructors
	 *
	 */
	Node(value_type value);
};

#include "red_black_tree_internals/Node_impl.hpp"
