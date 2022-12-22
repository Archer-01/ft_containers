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
	 */
	Node()
	{
		this->data = T();
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
		this->color = RED;
		this->side = LEFT;
	}

	Node(T data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
		this->color = RED;
		this->side = LEFT;
	}
};
