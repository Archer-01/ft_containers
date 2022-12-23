#pragma once

#include "RedBlackTree.hpp"
#include "test_algorithm.hpp"
#include <iterator>

// WARN: Remove me later
#include <iostream>

template <typename T, typename Compare, typename Allocator>
ft::RedBlackTree<T, Compare, Allocator>::RedBlackTree()
{
	m_Root = NULL;
	m_Size = 0;
	m_Allocator = Allocator();
	m_Compare = Compare();
}

template <typename T, typename Compare, typename Allocator>
ft::RedBlackTree<T, Compare, Allocator>::RedBlackTree(
	const Compare &comp,
	const Allocator &alloc
)
{
	m_Root = NULL;
	m_Size = 0;
	m_Allocator = alloc;
	m_Compare = comp;
}

template <typename T, typename Compare, typename Allocator>
template <typename InputIterator>
ft::RedBlackTree<T, Compare, Allocator>::RedBlackTree(
	InputIterator first,
	typename ft::enable_if<
		not ft::is_integral<InputIterator>::value,
		InputIterator
	>::type last,
	const Compare &comp,
	const Allocator &alloc
)
{
	m_Root = NULL;
	m_Size = 0;
	m_Allocator = alloc;
	m_Compare = comp;
	while (first != last)
	{
		this->insert(*first);
		++first;
	}
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::insert(T value)
{
	Node *node = NULL;

	node = new Node();
	m_Allocator.construct(&node->data, value);
	if (m_Root == NULL)
	{
		m_Root = node;
		m_Root->color = BLACK;
	}
	else
	{
		RecursiveInsert(m_Root, node, m_Compare);
	}
	++m_Size;
	// FIX: Add insertion fixup
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::RecursiveInsert(
	Node *root,
	Node *node,
	const Compare &comp
)
{
	assert(root != NULL);
	assert(node != NULL);

	if (comp(node->data, root->data) == true)
	{
		if (root->left == NULL)
		{
			root->left = node;
			node->parent = root;
			node->side = LEFT;
		}
		else
		{
			RecursiveInsert(root->left, node, comp);
		}
	}
	else
	{
		if (root->right == NULL)
		{
			root->right = node;
			node->parent = root;
			node->side = RIGHT;
		}
		else
		{
			RecursiveInsert(root->right, node, comp);
		}
	}
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::print() const
{
	RecursivePrint(m_Root);
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::RecursivePrint(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	RecursivePrint(root->left);
	std::cout << root->data << " ";
	RecursivePrint(root->right);
}

template <typename T, typename Compare, typename Allocator>
ft::RedBlackTree<T, Compare, Allocator>::~RedBlackTree()
{
	RecursiveDelete(m_Root, m_Allocator);
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::RecursiveDelete(Node *root, Allocator &alloc)
{
	if (root == NULL)
	{
		return;
	}
	RecursiveDelete(root->left, alloc);
	RecursiveDelete(root->right, alloc);
	alloc.destroy(&root->data);
	delete root;
}

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>&
ft::RedBlackTree<T, Compare, Allocator>::operator=(const RedBlackTree &other)
{
	if (this != &other)
	{
		RecursiveDelete(m_Root, m_Allocator);
		m_Size = 0;
		m_Allocator = other.m_Allocator;
		m_Compare = other.m_Compare;
		m_Root = this->copyTree(other.m_Root);
	}
	return *this;
}

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>::Node*
ft::RedBlackTree<T, Compare, Allocator>::copyTree(Node *srcRoot)
{
	Node *node = NULL;

	if (srcRoot == NULL)
	{
		return NULL;
	}
	node = new Node();
	*node = *srcRoot;
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
ft::RedBlackTree<T, Compare, Allocator>::RedBlackTree(const RedBlackTree &other)
{
	m_Size = 0;
	m_Allocator = other.m_Allocator;
	m_Compare = other.m_Compare;
	m_Root = this->copyTree(other.m_Root);
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::leftRotate(Node *grandParent)
{
	assert(grandParent != NULL);
	assert(grandParent->right != NULL);
	assert(grandParent->parent != NULL);

	Node *parent = NULL;
	
	parent = grandParent->right;
	grandParent->right = parent->left;
	if (parent->left != NULL) // Parent has a left sub-tree
	{
		parent->left->parent = grandParent;
		parent->left->side = RIGHT;
	}
	if (grandParent->parent == NULL) // Grand parent is the root node
	{
		m_Root = parent;
		m_Root->parent = NULL;
	}
	else // Grand parent is not the root node
	{
		parent->parent = grandParent->parent;
		parent->side = grandParent->side;
		if (parent->side == LEFT)
		{
			grandParent->parent->left = parent;
		}
		else
		{
			grandParent->parent->right = parent;
		}
	}
	// Rotate the grand parent around its right child
	parent->left = grandParent;
	grandParent->parent = parent;
	grandParent->side = LEFT;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::rightRotate(Node *grandParent)
{
	assert(grandParent != NULL);
	assert(grandParent->left != NULL);
	assert(grandParent->parent != NULL);

	Node *parent = NULL;

	parent = grandParent->left;
	grandParent->left = parent->right;
	if (parent->right != NULL) // Parent has a right sub-tree
	{
		parent->right->parent = grandParent;
		parent->right->side = LEFT;
	}
	if (grandParent->parent == NULL) // Grand parent is the root node
	{
		m_Root = parent;
		m_Root->parent = NULL;
	}
	else // Grand parent is not the root node
	{
		parent->parent = grandParent->parent;
		parent->side = grandParent->side;
		if (parent->side == LEFT)
		{
			grandParent->parent->left = parent;
		}
		else
		{
			grandParent->parent->right = parent;
		}
	}
	// Rotate the grand parent around its left child
	parent->right = grandParent;
	grandParent->parent = parent;
	grandParent->side = RIGHT;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::leftRightRotate(Node *grandParent)
{
	this->leftRotate(grandParent->left);
	this->rightRotate(grandParent);
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::rightLeftRotate(Node *grandParent)
{
	this->rightRotate(grandParent->right);
	this->leftRotate(grandParent);
}

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>::Node*
ft::RedBlackTree<T, Compare, Allocator>::Sibling(Node *node)
{
	assert(node != NULL);
	assert(node->parent != NULL);

	Node *sibling = NULL;

	if (node->side == LEFT)
	{
		sibling = node->parent->right;
	}
	else // node->side == RIGHT
	{
		sibling = node->parent->left;
	}
	return sibling;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::simpleRotationRecolor(Node *problemNode)
{
	assert(problemNode != NULL);
	assert(problemNode->parent != NULL);
	assert(problemNode->parent->parent != NULL);

	problemNode->parent->color = BLACK;
	Sibling(problemNode)->color = RED;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::doubleRotationRecolor(Node *problemNode)
{
	assert(problemNode != NULL);
	assert(problemNode->parent != NULL);
	assert(problemNode->parent->parent != NULL);

	problemNode->parent->color = BLACK;
	problemNode->parent->left->color = RED;
	problemNode->parent->right->color = RED;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::rotate(Node *problemNode)
{
	assert(problemNode != NULL);
	assert(problemNode->parent != NULL);
	assert(problemNode->parent->parent != NULL);

	if (problemNode->side == LEFT and problemNode->parent->side == LEFT)
	{
		this->rightRotate(problemNode->parent->parent);
		simpleRotationRecolor(problemNode);
	}
	else if (problemNode->side == RIGHT and problemNode->parent->side == RIGHT)
	{
		this->leftRotate(problemNode->parent->parent);
		simpleRotationRecolor(problemNode);
	}
	else if (problemNode->side == LEFT and problemNode->parent->side == RIGHT)
	{
		this->rightLeftRotate(problemNode->parent->parent);
		doubleRotationRecolor(problemNode);
	}
	else if (problemNode->side == RIGHT and problemNode->parent->side == LEFT)
	{
		this->leftRightRotate(problemNode->parent->parent);
		doubleRotationRecolor(problemNode);
	}
}

template <typename T, typename Compare, typename Allocator>
const typename ft::RedBlackTree<T, Compare, Allocator>::Node*
ft::RedBlackTree<T, Compare, Allocator>::aunt(const Node *node) const
{
	assert(node != NULL);
	assert(node->parent != NULL);
	assert(node->parent->parent != NULL);

	const Node *aunt = NULL;

	if (node->parent->side == LEFT)
	{
		aunt = node->parent->parent->right;
	}
	else
	{
		aunt = node->parent->parent->left;
	}
	return aunt;
}
