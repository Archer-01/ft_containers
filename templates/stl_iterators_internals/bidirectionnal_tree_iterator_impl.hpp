#pragma once

#include "bidirectionnal_tree_iterator.hpp"

template <typename NodeType, typename T>
ft::bidirectionnal_tree_iterator<NodeType, T>::bidirectionnal_tree_iterator()
	: current(NULL), root(NULL) {}

template <typename NodeType, typename T>
ft::bidirectionnal_tree_iterator<NodeType, T>::bidirectionnal_tree_iterator(
	node_pointer node,
	node_pointer root
) : current(node), root(root) {}

template <typename NodeType, typename T>
template <typename OtherNodeType, typename U>
ft::bidirectionnal_tree_iterator<NodeType, T>::bidirectionnal_tree_iterator(
	const bidirectionnal_tree_iterator<OtherNodeType, U> &rhs
) : current(rhs.getCurrent()), root(rhs.getRoot()) {}

template <typename NodeType, typename T>
template <typename OtherNodeType, typename U>
ft::bidirectionnal_tree_iterator<NodeType, T>&
ft::bidirectionnal_tree_iterator<NodeType, T>::operator=(
	const bidirectionnal_tree_iterator<OtherNodeType, U> &rhs
)
{
	current = rhs.getCurrent();
	root = rhs.getRoot();
	return *this;
}

template <typename NodeType, typename T>
typename ft::bidirectionnal_tree_iterator<NodeType, T>::node_pointer
ft::bidirectionnal_tree_iterator<NodeType, T>::getCurrent() const
{
	return this->current;
}

template <typename NodeType, typename T>
typename ft::bidirectionnal_tree_iterator<NodeType, T>::node_pointer
ft::bidirectionnal_tree_iterator<NodeType, T>::getRoot() const
{
	return this->root;
}

template <typename NodeType, typename T>
typename ft::bidirectionnal_tree_iterator<NodeType, T>::reference
ft::bidirectionnal_tree_iterator<NodeType, T>::operator*() const
{
	return this->current->value;
}

template <typename NodeType, typename T>
typename ft::bidirectionnal_tree_iterator<NodeType, T>::pointer
ft::bidirectionnal_tree_iterator<NodeType, T>::operator->() const
{
	return &this->current->value;
}

template <typename NodeType, typename T>
template <typename OtherNodeType, typename U>
bool ft::bidirectionnal_tree_iterator<NodeType, T>::operator==(
	const bidirectionnal_tree_iterator<OtherNodeType, U> &rhs
) const
{
	return this->root == rhs.getRoot() and this->current == rhs.getCurrent();
}

template <typename NodeType, typename T>
template <typename OtherNodeType, typename U>
bool ft::bidirectionnal_tree_iterator<NodeType, T>::operator!=(
	const bidirectionnal_tree_iterator<OtherNodeType, U> &rhs
) const
{
	return not (*this == rhs);
}

template <typename NodeType, typename T>
ft::bidirectionnal_tree_iterator<NodeType, T>&
ft::bidirectionnal_tree_iterator<NodeType, T>::operator++()
{
	if (this->current->right != NULL)
	{
		this->current = this->leftmostNode(this->current->right);
	}
	else // current node has no right child
	{
		while (this->current != NULL and this->current->side == RIGHT)
		{
			this->current = this->current->parent;
		}
		this->current = (this->current != NULL) ? this->current->parent : NULL;
	}
	return *this;
}

template <typename NodeType, typename T>
ft::bidirectionnal_tree_iterator<NodeType, T>
ft::bidirectionnal_tree_iterator<NodeType, T>::operator++(int)
{
	bidirectionnal_tree_iterator tmp = *this;

	++(*this);
	return tmp;
}

template <typename NodeType, typename T>
typename ft::bidirectionnal_tree_iterator<NodeType, T>::node_pointer
ft::bidirectionnal_tree_iterator<NodeType, T>::leftmostNode(
	node_pointer node
) const
{
	assert(node != NULL);

	while (node->left != NULL)
	{
		node = node->left;
	}
	return node;
}

template <typename NodeType, typename T>
ft::bidirectionnal_tree_iterator<NodeType, T>&
ft::bidirectionnal_tree_iterator<NodeType, T>::operator--()
{
	if (this->current != NULL and this->current->left != NULL)
	{
		this->current = this->rightmostNode(this->current->left);
	}
	else // current node has no left child
	{
		while (this->current != NULL and this->current->side == LEFT)
		{
			this->current = this->current->parent;
		}
		this->current = (this->current != NULL) ?
						this->current->parent : this->rightmostNode(this->root);
	}
	return *this;
}

template <typename NodeType, typename T>
ft::bidirectionnal_tree_iterator<NodeType, T>
ft::bidirectionnal_tree_iterator<NodeType, T>::operator--(int)
{
	bidirectionnal_tree_iterator tmp = *this;

	--(*this);
	return tmp;
}

template <typename NodeType, typename T>
typename ft::bidirectionnal_tree_iterator<NodeType, T>::node_pointer
ft::bidirectionnal_tree_iterator<NodeType, T>::rightmostNode(
	node_pointer node
) const
{
	assert(node != NULL);

	while (node->right != NULL)
	{
		node = node->right;
	}
	return node;
}
