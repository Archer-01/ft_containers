#pragma once

#include "Node.hpp"
#include <cassert>

template <typename T, typename Allocator>
ft::Node<T, Allocator>::Node(value_type value) : color(RED), side(LEFT)
{
	allocator_type allocator;

	allocator.construct(&this->value, value);
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

template <typename T, typename Allocator>
ft::Node<T, Allocator>::Node(const Node &rhs) : color(rhs.color), side(rhs.side)
{
	allocator_type allocator;

	allocator.construct(&this->value, rhs.value);
	this->left = rhs.left;
	this->right = rhs.right;
	this->parent = rhs.parent;
}

template <typename T, typename Allocator>
ft::Node<T, Allocator> &ft::Node<T, Allocator>::operator=(
	const Node<T, Allocator> &rhs
)
{
	if (this != &rhs)
	{
		allocator_type allocator;

		allocator.construct(&this->value, rhs.value);
		this->color = rhs.color;
		this->side = rhs.side;
		this->left = rhs.left;
		this->right = rhs.right;
		this->parent = rhs.parent;
	}
	return *this;
}

template <typename T, typename Allocator>
ft::Node<T, Allocator>::~Node()
{
	allocator_type allocator;

	allocator.destroy(&this->value);
}

template <typename T, typename Allocator>
ft::Node<T, Allocator> *ft::Node<T, Allocator>::getGrandParent() const
{
	assert(this->parent != NULL);

	return this->parent->parent;
}

template <typename T, typename Allocator>
ft::Node<T, Allocator> *ft::Node<T, Allocator>::getAunt() const
{
	Node *grandParent = this->getGrandParent();

	if (this->parent->side == LEFT)
	{
		return grandParent->right;
	}
	return grandParent->left;
}

template <typename T, typename Allocator>
ft::Node<T, Allocator> *ft::Node<T, Allocator>::getSuccessor() const
{
	Node *successor = this->right;

	while (successor->left != NULL)
	{
		successor = successor->left;
	}
	return successor;
}

template <typename T, typename Allocator>
ft::Node<T, Allocator> *ft::Node<T, Allocator>::getChild(NodeSide side) const
{
	if (side == LEFT)
	{
		return this->left;
	}
	return this->right;
}

template <typename T, typename Allocator>
ft::Node<T, Allocator> *ft::Node<T, Allocator>::getOtherChild(NodeSide side) const
{
	if (side == LEFT)
	{
		return this->right;
	}
	return this->left;
}

template <typename T, typename Allocator>
bool ft::Node<T, Allocator>::IsRed(const Node *node)
{
	return node != NULL and node->color == RED;
}

template <typename T, typename Allocator>
bool ft::Node<T, Allocator>::IsBlack(const Node *node)
{
	return node == NULL or node->color == BLACK;
}

template <typename T, typename Allocator>
void ft::Node<T, Allocator>::linkChild(Node *child, NodeSide side)
{
	if (side == LEFT)
	{
		this->left = child;
	}
	else // side == RIGHT
	{
		this->right = child;
	}

	if (child != NULL)
	{
		child->parent = this;
		child->side = side;
	}
}
