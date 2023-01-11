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
	Node(const Node &rhs);

	/**
	 * @def Assignment operator
	 *
	 */
	Node &operator=(const Node &rhs);

	/**
	 * @def Destructor
	 *
	 */
	~Node();

	/**
	 * @def Methods
	 *
	 */
	Node *getGrandParent() const;
	Node *getAunt() const;

	static bool IsRed(const Node *node);
	static bool IsBlack(const Node *node);
};

#include "red_black_tree_internals/Node_impl.hpp"
