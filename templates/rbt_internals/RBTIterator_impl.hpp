#pragma once

#include "RBTIterator.hpp"

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
typename ft::RedBlackTree<T, Compare, Allocator>::template Iterator<NodeType, U>::node_pointer
ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::leftmostNode(
	node_pointer start
) const
{
	node_pointer result = start;

	while (result != NULL and result->left != NULL)
	{
		result = result->left;
	}
	return result;
}

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
typename ft::RedBlackTree<T, Compare, Allocator>::template Iterator<NodeType, U>::node_pointer
ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::rightmostNode(
	node_pointer start
) const
{
	node_pointer result = start;

	while (result != NULL and result->right != NULL)
	{
		result = result->right;
	}
	return result;
}

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::Iterator()
{
	m_Current = NULL;
	m_Root = NULL;
}

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::Iterator(
	node_pointer root,
	node_pointer current
)
{
	m_Root = root;
	m_Current = this->leftmostNode(current);
}

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
template <typename OtherNodeType, typename V>
ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::Iterator(
	const Iterator<OtherNodeType, V> &rhs
)
{
	m_Current = rhs.getCurrent();
	m_Root = rhs.getRoot();
}

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
typename ft::RedBlackTree<T, Compare, Allocator>::template Iterator<NodeType, U>::node_pointer
ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::getCurrent() const
{
	return m_Current;
}

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
typename ft::RedBlackTree<T, Compare, Allocator>::template Iterator<NodeType, U>::node_pointer
ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::getRoot() const
{
	return m_Root;
}

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
template <typename OtherNodeType, typename V>
typename ft::RedBlackTree<T, Compare, Allocator>::template Iterator<NodeType, U>&
ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::operator=(
	const Iterator<OtherNodeType, V> &rhs
)
{
	m_Root = rhs.getRoot();
	m_Current = rhs.getCurrent();
	return *this;
}

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
typename ft::RedBlackTree<T, Compare, Allocator>::template Iterator<NodeType, U>::reference
ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::operator*() const
{
	return m_Current->data;
}

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
typename ft::RedBlackTree<T, Compare, Allocator>::template Iterator<NodeType, U>::pointer
ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::operator->() const
{
	return &m_Current->data;
}

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
typename ft::RedBlackTree<T, Compare, Allocator>::template Iterator<NodeType, U>&
ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::operator++()
{
	if (m_Current->right != NULL)
	{
		m_Current = this->leftmostNode(m_Current->right);
	}
	else // m_Current->right == NULL
	{
		while (m_Current != NULL and m_Current->side == RIGHT)
		{
			m_Current = m_Current->parent;
		}
		m_Current = (m_Current != NULL) ? m_Current->parent : NULL;
	}
	return *this;
}

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
typename ft::RedBlackTree<T, Compare, Allocator>::template Iterator<NodeType, U>
ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::operator++(int)
{
	Iterator<NodeType, U> result = *this;

	++(*this);
	return result;
}

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
typename ft::RedBlackTree<T, Compare, Allocator>::template Iterator<NodeType, U>&
ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::operator--()
{
	if (m_Current != NULL and m_Current->left != NULL)
	{
		m_Current = this->rightmostNode(m_Current->left);
	}
	else // m_Current->left == NULL
	{
		while (m_Current != NULL and m_Current->side == LEFT)
		{
			m_Current = m_Current->parent;
		}
		m_Current = (m_Current != NULL) ? m_Current->parent : rightmostNode(m_Root);
	}
	return *this;
}

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
typename ft::RedBlackTree<T, Compare, Allocator>::template Iterator<NodeType, U>
ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::operator--(int)
{
	Iterator<NodeType, U> result = *this;

	--(*this);
	return result;
}

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
template <typename OtherNodeType, typename V>
bool ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::operator==(
	const Iterator<OtherNodeType, V> &rhs
) const
{
	return m_Current == rhs.getCurrent();
}

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
template <typename OtherNodeType, typename V>
bool ft::RedBlackTree<T, Compare, Allocator>::Iterator<NodeType, U>::operator!=(
	const Iterator<OtherNodeType, V> &rhs
) const
{
	return m_Current != rhs.getCurrent();
}
