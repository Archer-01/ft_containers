#pragma once

#include "RBTNode.hpp"
#include "RedBlackTree.hpp"
#include <memory>

template <typename T, typename Compare, typename Allocator>
ft::RedBlackTree<T, Compare, Allocator>::Node::Node()
{
	this->data = T();
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
	this->color = RED;
	this->side = LEFT;
}

template <typename T, typename Compare, typename Allocator>
ft::RedBlackTree<T, Compare, Allocator>::Node::Node(T data)
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

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>::Node*
ft::RedBlackTree<T, Compare, Allocator>::Node::sibling()
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

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>::Node*
ft::RedBlackTree<T, Compare, Allocator>::Node::aunt()
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

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>::Node*
ft::RedBlackTree<T, Compare, Allocator>::Node::grandParent()
{
	assert(this != NULL);
	assert(this->parent != NULL);
	assert(this->parent->parent != NULL);

	return this->parent->parent;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::Node::swapColorsWith(
	Node *otherNode
)
{
	assert(this != NULL);
	assert(otherNode != NULL);

	NodeColor tempColor = this->color;

	this->color = otherNode->color;
	otherNode->color = tempColor;
}

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>::Node*
ft::RedBlackTree<T, Compare, Allocator>::Node::getSuccessor()
{
	assert(this != NULL);
	assert(this->right != NULL);

	Node *successor = this->right;

	while (successor->left != NULL)
	{
		successor = successor->left;
	}
	return successor;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::Node::linkChild(
	Node *child,
	NodeSide side
)
{
	assert(this != NULL);

	if (side == LEFT)
	{
		this->left = child;
		if (child != NULL)
		{
			child->parent = this;
			child->side = LEFT;
		}
	}
	else // side == RIGHT
	{
		this->right = child;
		if (child != NULL)
		{
			child->parent = this;
			child->side = RIGHT;
		}
	}
}