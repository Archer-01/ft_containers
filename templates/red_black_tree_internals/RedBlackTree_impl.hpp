#pragma once

#include "RedBlackTree.hpp"

template <typename T, typename Compare, typename Allocator>
ft::RedBlackTree<T, Compare, Allocator>::RedBlackTree() : root(NULL), compare(), allocator() {}

template <typename T, typename Compare, typename Allocator>
ft::RedBlackTree<T, Compare, Allocator>::RedBlackTree(
	const value_compare &comp,
	const allocator_type &alloc
) : root(NULL), compare(comp), allocator(alloc) {}

template <typename T, typename Compare, typename Allocator>
template <typename InputIterator>
ft::RedBlackTree<T, Compare, Allocator>::RedBlackTree(
	InputIterator first,
	InputIterator last,
	const value_compare &comp,
	const allocator_type &alloc
// HACK: Notice me
/* ) : root(NULL), compare(comp), allocator(alloc) */
) : RedBlackTree(comp, alloc)
{
	#pragma unroll
	while (first != last)
	{
		this->insert(*first);
		++first;
	}
}

template <typename T, typename Compare, typename Allocator>
ft::RedBlackTree<T, Compare, Allocator>::~RedBlackTree()
{
	this->clear(this->root);
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::clear(node_type *root)
{
	if (root == NULL)
	{
		return;
	}
	this->clear(root->left);
	this->clear(root->right);
	this->allocator.destroy(&root->value);
	delete root;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::insert(const value_type &value)
{
	node_type *node = this->root;

	while (node != NULL)
	{
		if (this->compare(value, node->value))
		{
			if (node->left == NULL)
			{
				node->left = new node_type(value);
				node->left->parent = node;
				node->left->side = LEFT;
				break;
			}
			node = node->left;
		}
		else
		{
			if (node->right == NULL)
			{
				node->right = new node_type(value);
				node->right->parent = node;
				node->right->side = RIGHT;
				break;
			}
			node = node->right;
		}
	}
	// TODO: insertFixup(node);
}
