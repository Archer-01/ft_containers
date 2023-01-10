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
