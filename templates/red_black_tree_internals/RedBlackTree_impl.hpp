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
) : root(NULL), compare(comp), allocator(alloc)
{
	#pragma unroll
	while (first != last)
	{
		this->insert(*first);
		++first;
	}
}

template <typename T, typename Compare, typename Allocator>
ft::RedBlackTree<T, Compare, Allocator>::RedBlackTree(const RedBlackTree &rhs)
	: root(NULL), compare(rhs.compare), allocator(rhs.allocator)
{
	this->copyTree(rhs.root);
}

template <typename T, typename Compare, typename Allocator>
ft::RedBlackTree<T, Compare, Allocator>::~RedBlackTree()
{
	this->clear(this->root);
}

template <typename T, typename Compare, typename Allocator>
ft::RedBlackTree<T, Compare, Allocator>
&ft::RedBlackTree<T, Compare, Allocator>::operator=(
	const RedBlackTree &rhs
)
{
	if (this != &rhs)
	{
		this->clear(this->root);
		this->copyTree(rhs.root);
		this->compare = rhs.compare;
		this->allocator = rhs.allocator;
	}
	return *this;
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

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>::node_type*
ft::RedBlackTree<T, Compare, Allocator>::copyTree(node_type *srcRoot)
{
	if (srcRoot == NULL)
	{
		return NULL;
	}

	node_type *node = new node_type(*srcRoot);

	node->left = copyTree(srcRoot->left);
	if (node->left != NULL)
	{
		node->left->parent = node;
		node->left->side = LEFT;
	}
	node->right = copyTree(srcRoot->right);
	if (node->right != NULL)
	{
		node->right->parent = node;
		node->right->side = RIGHT;
	}
	return node;
}
