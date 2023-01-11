#pragma once

#include "Node.hpp"

template <typename T, typename Allocator>
ft::Node<T, Allocator>::Node(value_type value) : value(value), color(RED), side(LEFT)
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
	assert(this != NULL and this->parent != NULL);

	return this->parent->parent;
}

template <typename T, typename Allocator>
ft::Node<T, Allocator> *ft::Node<T, Allocator>::getAunt() const
{
	assert(this != NULL);

	Node *grandParent = this->getGrandParent();

	if (this->parent->side == LEFT)
	{
		return grandParent->right;
	}
	return grandParent->left;
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
