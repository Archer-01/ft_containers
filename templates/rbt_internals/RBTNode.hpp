#pragma once

#include "RedBlackTree.hpp"
#include <cstddef>

template <typename T, typename Compare, typename Allocator>
struct ft::RedBlackTree<T, Compare, Allocator>::Node
{
	/**
	 * @defgroup Attributes
	 *
	 */

	T data;
	Node *left;
	Node *right;
	Node *parent;
	NodeColor color;
	NodeSide side;

	/**
	 * @defgroup Constructors
	 *
	 * - Default Constructor
	 * - Parameterized Constructor
	 */

	Node();
	Node(T data);

	/**
	 * @def Helper methods
	 *
	 * - Sibling
	 * - Aunt
	 * - Grandparent
	 * - Replace with
	 * - Swap colors
	 * - Get successor
	 * - Is black
	 * - Is red
	 *
	 */

	Node *getSibling();
	Node *getAunt();
	Node *getGrandParent();
	void swapColorsWith(Node *otherNode);
	Node *getSuccessor();
	void linkChild(Node *child, NodeSide side);
	static bool IsBlack(const Node *node);
	static bool IsRed(const Node *node);
};

#include "RBTNode_impl.hpp"
