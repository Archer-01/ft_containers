#pragma once

#include "bidirectionnal_tree_iterator.hpp"

template <typename Node, typename T>
ft::bidirectionnal_tree_iterator<Node, T>::bidirectionnal_tree_iterator() : current(NULL), root(NULL) {}

template <typename Node, typename T>
ft::bidirectionnal_tree_iterator<Node, T>::bidirectionnal_tree_iterator(
	node_pointer node,
	node_pointer root
) : current(node), root(root) {}

template <typename Node, typename T>
template <typename OtherNode, typename U>
ft::bidirectionnal_tree_iterator<Node, T>::bidirectionnal_tree_iterator(
	const bidirectionnal_tree_iterator<OtherNode, U> &rhs
) : current(rhs.getCurrent()), root(rhs.getRoot()) {}

template <typename Node, typename T>
template <typename OtherNode, typename U>
ft::bidirectionnal_tree_iterator<Node, T>&
ft::bidirectionnal_tree_iterator<Node, T>::operator=(
	const bidirectionnal_tree_iterator<OtherNode, U> &rhs
)
{
	current = rhs.getCurrent();
	root = rhs.getRoot();
	return *this;
}

template <typename Node, typename T>
typename ft::bidirectionnal_tree_iterator<Node, T>::node_pointer
ft::bidirectionnal_tree_iterator<Node, T>::getCurrent() const
{
	return this->current;
}

template <typename Node, typename T>
typename ft::bidirectionnal_tree_iterator<Node, T>::node_pointer
ft::bidirectionnal_tree_iterator<Node, T>::getRoot() const
{
	return this->root;
}

template <typename Node, typename T>
typename ft::bidirectionnal_tree_iterator<Node, T>::reference
ft::bidirectionnal_tree_iterator<Node, T>::operator*() const
{
	return this->current->value;
}

template <typename Node, typename T>
typename ft::bidirectionnal_tree_iterator<Node, T>::pointer
ft::bidirectionnal_tree_iterator<Node, T>::operator->() const
{
	return &this->current->value;
}

template <typename Node, typename T>
template <typename OtherNode, typename U>
bool ft::bidirectionnal_tree_iterator<Node, T>::operator==(
	const bidirectionnal_tree_iterator<OtherNode, U> &rhs
) const
{
	return this->root == rhs.getRoot() and this->current == rhs.getCurrent();
}

template <typename Node, typename T>
template <typename OtherNode, typename U>
bool ft::bidirectionnal_tree_iterator<Node, T>::operator!=(
	const bidirectionnal_tree_iterator<OtherNode, U> &rhs
) const
{
	return not (*this == rhs);
}
