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

	/**
	 * @def Sibling method
	 *
	 */

	Node *sibling()
	{
		assert(this != NULL);
		assert(this->parent != NULL);

		Node *sibling = NULL;

		if (this->side == LEFT)
		{
			sibling = this->parent->right;
		}
		else // this->side == RIGHT
		{
			sibling = this->parent->left;
		}
		return sibling;
	}

	Node *aunt()
	{
		assert(this != NULL);
		assert(this->parent != NULL);
		assert(this->parent->parent != NULL);

		Node *aunt = NULL;

		if (this->parent->side == LEFT)
		{
			aunt = this->parent->parent->right;
		}
		else // this->parent->side == RIGHT
		{
			aunt = this->parent->parent->left;
		}
		return aunt;
	}

	Node *grandParent()
	{
		assert(this != NULL);
		assert(this->parent != NULL);
		assert(this->parent->parent != NULL);

		return this->parent->parent;
	}

};
