#pragma once

#include "map.hpp"

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>::map()
	: m_Tree(tree_type(value_compare(Compare())))
{
	// Empty body
}

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>::map(
	const key_compare &comp,
	const allocator_type &alloc
) : m_Tree(tree_type(value_compare(comp), alloc))
{
	// Empty body
}

template <typename Key, typename T, typename Compare, typename Allocator>
template <typename InputIterator>
ft::map<Key, T, Compare, Allocator>::map(
	InputIterator first,
	typename ft::enable_if<
		not ft::is_integral<InputIterator>::value,
		InputIterator
	>::type last,
	const key_compare &comp,
	const allocator_type &alloc
) : m_Tree(tree_type(first, last, value_compare(comp), alloc))
{
	// Empty body
}

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>::map(const map &other): m_Tree(other.m_Tree)
{
	// Empty body
}

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>::~map()
{
	// Empty body
}

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>&
ft::map<Key, T, Compare, Allocator>::operator=(const map &other)
{
	if (this != &other)
	{
		m_Tree = other.m_Tree;
	}
	return *this;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::allocator_type
ft::map<Key, T, Compare, Allocator>::get_allocator() const
{
	return m_Tree.get_allocator();
}

template <typename Key, typename T, typename Compare, typename Allocator>
T& ft::map<Key, T, Compare, Allocator>::at(const Key &key)
{
	typename tree_type::Node *root = m_Tree.get_root();
	Compare comp;

	while (root != NULL)
	{
		if (comp(key, root->data.first))
		{
			root = root->left;
		}
		else if (comp(root->data.first, key))
		{
			root = root->right;
		}
		else // key == node->value.first
		{
			return root->data.second;
		}
	}
	throw std::out_of_range("map::at: key not found");
}

template <typename Key, typename T, typename Compare, typename Allocator>
T& ft::map<Key, T, Compare, Allocator>::operator[](const Key &key)
{
	typename tree_type::Node *root = m_Tree.get_root();
	Compare comp;

	while (root != NULL)
	{
		if (comp(key, root->data.first))
		{
			root = root->left;
		}
		else if (comp(root->data.first, key))
		{
			root = root->right;
		}
		else // key == node->value.first
		{
			return root->data.second;
		}
	}
	return m_Tree.insert(value_type(key, T())).first->second;
}
