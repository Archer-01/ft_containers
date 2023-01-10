#pragma once

namespace ft
{

	enum NodeSide
	{
		LEFT,
		RIGHT
	};

	enum NodeColor
	{
		RED,
		BLACK
	};

	template <typename T, typename Allocator>
	struct Node;

	template <typename T, typename Compare, typename Allocator>
	class RedBlackTree;

}; // namespace ft

#include "red_black_tree_internals/Node.hpp"
#include "red_black_tree_internals/RedBlackTree.hpp"
