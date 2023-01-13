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
void ft::RedBlackTree<T, Compare, Allocator>::clear()
{
	this->clear(this->root);
	this->root = NULL;
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
ft::pair<typename ft::RedBlackTree<T, Compare, Allocator>::iterator, bool>
ft::RedBlackTree<T, Compare, Allocator>::insert(const value_type &value)
{
	node_type *node = this->find(value);

	if (node != NULL)
	{
		return ft::make_pair(iterator(node, this->root), false);
	}

	node_type *newNode = new node_type(value);

	if (this->root == NULL)
	{
		this->root = newNode;
		this->root->color = BLACK;
		return ft::make_pair(iterator(this->root, this->root), true);
	}
	node = this->root;
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
	return ft::make_pair(iterator(newNode, this->root), true);
}

template <typename T, typename Compare, typename Allocator>
ft::pair<typename ft::RedBlackTree<T, Compare, Allocator>::iterator, bool>
ft::RedBlackTree<T, Compare, Allocator>::insertAt(
	iterator position,
	const value_type &value
)
{
	if (position == this->end())
	{
		return this->insert(value);
	}

	node_type *root = position.getCurrent();

	if (this->compare(value, root->value))
	{
		return this->insertAt(
			iterator(root->left, this->root),
			value
		);
	}
	return this->insertAt(
		iterator(root->right, this->root),
		value
	);
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

template <typename T, typename Compare, typename Allocator>
typename ft::RedBlackTree<T, Compare, Allocator>::node_type*
ft::RedBlackTree<T, Compare, Allocator>::find(const value_type &value) const
{
	node_type *node = this->root;

	while (node != NULL)
	{
		if (this->compare(value, node->value))
		{
			node = node->left;
		}
		else if (this->compare(node->value, value))
		{
			node = node->right;
		}
		else // found the value
		{
			return node;
		}
	}
	return NULL;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::erase(const value_type &value)
{
	node_type *node = this->find(value);

	if (node == NULL)
	{
		return;
	}
	this->erase(node);
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::erase(node_type *nodeToErase)
{
	assert(nodeToErase != NULL);

	NodeColor removedColor = nodeToErase->color;
	NodeSide fixupSide = nodeToErase->side;
	node_type *fixupNode = (nodeToErase->parent != NULL) ? nodeToErase->parent : this->root;

	if (nodeToErase->left == NULL)
	{
		this->transplant(nodeToErase, nodeToErase->right);
	}
	else if (nodeToErase->right == NULL)
	{
		this->transplant(nodeToErase, nodeToErase->left);
	}
	else // nodeToErase has both left and right sub-trees
	{
		node_type *successor = nodeToErase->getSuccessor();

		fixupNode = successor;
		fixupSide = RIGHT;
		removedColor = successor->color;
		if (successor->parent != nodeToErase)
		{
			fixupSide = LEFT;
			fixupNode = successor->parent;
			this->transplant(successor, successor->right);
			successor->linkChild(nodeToErase->right, RIGHT);
		}
		this->transplant(nodeToErase, successor);
		successor->linkChild(nodeToErase->left, LEFT);
		successor->color = nodeToErase->color;
	}

	if (fixupNode == NULL or fixupNode == this->root)
	{
		if (fixupNode == this->root)
		{
			fixupNode->color = BLACK;
		}
		delete nodeToErase;
		return;
	}

	if (removedColor == BLACK)
	{
		this->eraseFixup(fixupNode, fixupSide);
	}
	delete nodeToErase;
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::transplant(
	const node_type *nodeToErase,
	node_type *replacement
)
{
	assert(nodeToErase != NULL);

	if (nodeToErase->parent == NULL)
	{
		this->root = replacement;
		if (replacement != NULL)
		{
			replacement->parent = NULL;
		}
	}
	else if (nodeToErase->side == LEFT)
	{
		nodeToErase->parent->left = replacement;
	}
	else // nodeToErase is a right child
	{
		nodeToErase->parent->right = replacement;
	}

	if (replacement != NULL)
	{
		replacement->parent = nodeToErase->parent;
		replacement->side = nodeToErase->side;
	}
}

template <typename T, typename Compare, typename Allocator>
void ft::RedBlackTree<T, Compare, Allocator>::eraseFixup(
	node_type *fixupNode,
	NodeSide fixupSide
)
{
	node_type *extraBlack = fixupNode->getChild(fixupSide);

	while (extraBlack != this->root and node_type::IsBlack(extraBlack))
	{
		node_type *parent = (extraBlack == NULL) ? fixupNode : extraBlack->parent;
		node_type *sibling = NULL;

		fixupSide = (extraBlack == NULL) ? fixupSide : extraBlack->side;
		sibling = parent->getOtherChild(fixupSide);

		if (node_type::IsRed(sibling))
		{
			sibling->color = BLACK;
			parent->color = RED;
			(fixupSide == LEFT) ? leftRotation(parent) : rightRotation(parent);
			sibling = parent->getOtherChild(fixupSide);
		}

		if (node_type::IsBlack(sibling->left) and node_type::IsBlack(sibling->right))
		{
			sibling->color = RED;
			extraBlack = parent;
		}
		else
		{
			if (node_type::IsBlack(sibling->getOtherChild(fixupSide)))
			{
				sibling->getChild(fixupSide)->color = BLACK;
				sibling->color = RED;
				(fixupSide == LEFT) ? rightRotation(sibling) : leftRotation(sibling);
				sibling = parent->getOtherChild(fixupSide);
			}
			sibling->color = parent->color;
			parent->color = BLACK;
			sibling->getOtherChild(fixupSide)->color = BLACK;
			(fixupSide == LEFT) ? leftRotation(parent) : rightRotation(parent);
			extraBlack = this->root;
		}
	}
	(extraBlack != NULL) ? extraBlack->color = BLACK : 0;
}
