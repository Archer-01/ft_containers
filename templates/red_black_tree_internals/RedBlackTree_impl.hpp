#pragma once

#include "RedBlackTree.hpp"

template <typename T, typename Compare, typename Allocator>
ft::RedBlackTree<T, Compare, Allocator>::RedBlackTree() : root(NULL) {}

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
	this->root = this->copyTree(rhs.root);
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
		this->root = this->copyTree(rhs.root);
		this->compare = rhs.compare;
		this->allocator = rhs.allocator;
	}
	return *this;
}

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>::node_type*
ft::RedBlackTree<T, Compare, Allocator>::getRoot() const
{
	return this->root;
}

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>::allocator_type
ft::RedBlackTree<T, Compare, Allocator>::getAllocator() const
{
	return this->allocator;
}

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>::value_compare
ft::RedBlackTree<T, Compare, Allocator>::getCompare() const
{
	return this->compare;
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
	delete root;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::insert(const value_type &value)
{
	node_type *node = this->root;
	node_type *newNode = new node_type(value);

	if (node == NULL)
	{
		this->root = newNode;
		this->root->color = BLACK;
		return;
	}
	while (node != NULL)
	{
		if (this->compare(value, node->value))
		{
			if (node->left == NULL)
			{
				node->left = newNode;
				newNode->parent = node;
				newNode->side = LEFT;
				break;
			}
			node = node->left;
		}
		else // value is great than node->value
		{
			if (node->right == NULL)
			{
				node->right = newNode;
				newNode->parent = node;
				newNode->side = RIGHT;
				break;
			}
			node = node->right;
		}
	}
	this->insertFixup(newNode);
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

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::insertFixup(node_type *problemNode)
{
	assert(problemNode != NULL and problemNode->color == RED);

	#pragma unroll
	while (problemNode != this->root and problemNode->parent->color == RED)
	{
		node_type *aunt = problemNode->getAunt();

		if (node_type::IsRed(aunt))
		{
			this->colorFlip(problemNode);
			problemNode = problemNode->getGrandParent();
		}
		else // aunt is black
		{
			this->rotation(problemNode);
			break;
		}
	}
	this->root->color = BLACK;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::colorFlip(node_type *problemNode)
{
	node_type *grandParent = problemNode->getGrandParent();

	assert(grandParent != NULL);

	grandParent->color = RED;
	grandParent->left->color = BLACK;
	grandParent->right->color = BLACK;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::rotation(node_type *problemNode)
{
	node_type *grandParent = problemNode->getGrandParent();
	node_type *parent = problemNode->parent;

	if (parent->side == LEFT)
	{
		if (problemNode->side == LEFT)
		{
			this->rightRotation(grandParent);
			problemNode->parent->color = BLACK;
			problemNode->parent->right->color = RED;
		}
		else // problemNode is a right child
		{
			this->leftRotation(parent);
			this->rightRotation(grandParent);
			problemNode->color = BLACK;
			problemNode->left->color = RED;
			problemNode->right->color = RED;
		}
	}
	else // parent is a right child
	{
		if (problemNode->side == RIGHT)
		{
			this->leftRotation(grandParent);
			problemNode->parent->color = BLACK;
			problemNode->parent->left->color = RED;
		}
		else // problemNode is a left child
		{
			this->rightRotation(parent);
			this->leftRotation(grandParent);
			problemNode->color = BLACK;
			problemNode->left->color = RED;
			problemNode->right->color = RED;
		}
	}
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::leftRotation(node_type *grandParent)
{
	assert(grandParent != NULL and grandParent->right != NULL);

	node_type *parent = grandParent->right;

	grandParent->right = parent->left;
	if (parent->left != NULL) // Parent has a left sub-tree
	{
		parent->left->parent = grandParent;
		parent->left->side = RIGHT;
	}
	if (grandParent->parent == NULL) // grandParent is the root node
	{
		this->root = parent;
		this->root->parent = NULL;
	}
	else // grandParent is not the root node
	{
		parent->parent = grandParent->parent;
		parent->side = grandParent->side;
		if (parent->side == LEFT)
		{
			grandParent->parent->left = parent;
		}
		else // parent is a right child
		{
			grandParent->parent->right = parent;
		}
	}
	parent->left = grandParent;
	grandParent->parent = parent;
	grandParent->side = LEFT;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::rightRotation(node_type *grandParent)
{
	assert(grandParent != NULL and grandParent->left != NULL);

	node_type *parent = grandParent->left;

	grandParent->left = parent->right;
	if (parent->right != NULL) // Parent has a right sub-tree
	{
		parent->right->parent = grandParent;
		parent->right->side = LEFT;
	}
	if (grandParent->parent == NULL) // grandParent is the root node
	{
		this->root = parent;
		this->root->parent = NULL;
	}
	else // grandParent is not the root node
	{
		parent->parent = grandParent->parent;
		parent->side = grandParent->side;
		if (parent->side == LEFT)
		{
			grandParent->parent->left = parent;
		}
		else // parent is a right child
		{
			grandParent->parent->right = parent;
		}
	}
	parent->right = grandParent;
	grandParent->parent = parent;
	grandParent->side = RIGHT;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::Print(node_type *node, int indent)
{
	if (node == NULL)
	{
		return;
	}
	if (node->right)
	{
		Print(node->right, indent + 4);
	}
	if (indent != 0)
	{
		std::cout << std::setw(indent) << ' ';
	}
	if (node->right)
	{
		std::cout << " /\n" << std::setw(indent) << ' ';
	}
	std::cout << (node->color == RED ? "\033[1;31m" : "\033[1;34m");
	std::cout << node->value << "\033[0m" << std::endl;
	if (node->left)
	{
		std::cout << std::setw(indent) << ' ' << " \\\n";
		Print(node->left, indent + 4);
	}
	std::cout << std::endl;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::print() const
{
	Print(this->root, 0);
}

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>::iterator
ft::RedBlackTree<T, Compare, Allocator>::begin()
{
	node_type *min = this->root;

	while (min != NULL and min->left != NULL)
	{
		min = min->left;
	}
	return iterator(min, this->root);
}

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>::const_iterator
ft::RedBlackTree<T, Compare, Allocator>::begin() const
{
	node_type *min = this->root;

	while (min != NULL and min->left != NULL)
	{
		min = min->left;
	}
	return const_iterator(min, this->root);
}

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>::iterator
ft::RedBlackTree<T, Compare, Allocator>::end()
{
	return iterator(NULL, this->root);
}

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>::const_iterator
ft::RedBlackTree<T, Compare, Allocator>::end() const
{
	return const_iterator(NULL, this->root);
}
