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

}; // namespace ft

#include "red_black_tree_internals/Node.hpp"
