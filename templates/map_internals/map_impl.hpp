#pragma once

#include "map.hpp"

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>::map() : tree(Allocator(), value_compare(Compare())) {}

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>::map(
	const Compare &comp,
	const Allocator &alloc
) : tree(value_compare(comp), alloc) {}

template <typename Key, typename T, typename Compare, typename Allocator>
template <typename InputIterator>
ft::map<Key, T, Compare, Allocator>::map(
	InputIterator first,
	InputIterator last,
	const Compare &comp,
	const Allocator &alloc
) : tree(first, last, value_compare(comp), alloc) {}

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>::map(const map &other) : tree(other.tree) {}

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>::~map() { (void) this; }

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>&
ft::map<Key, T, Compare, Allocator>::operator=(const map &other)
{
	if (this != &other)
	{
		this->tree = other.tree;
	}
	return *this;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::allocator_type
ft::map<Key, T, Compare, Allocator>::get_allocator() const
{
	return this->tree.getAllocator();
}

template <typename Key, typename T, typename Compare, typename Allocator>
T &ft::map<Key, T, Compare, Allocator>::at(const Key &key)
{
	node_type *node = this->tree.getRoot();
	key_compare comp;

	while (node != NULL)
	{
		if (comp(key, node->value.first))
		{
			node = node->left;
		}
		else if (comp(node->value.first, key))
		{
			node = node->right;
		}
		else // found the key
		{
			return node->value.second;
		}
	}
	throw std::out_of_range("map::at: key not found");
}

template <typename Key, typename T, typename Compare, typename Allocator>
const T &ft::map<Key, T, Compare, Allocator>::at(const Key &key) const
{
	node_type *node = this->tree.getRoot();
	key_compare comp;

	while (node != NULL)
	{
		if (comp(key, node->value.first))
		{
			node = node->left;
		}
		else if (comp(node->value.first, key))
		{
			node = node->right;
		}
		else // found the key
		{
			return node->value.second;
		}
	}
	throw std::out_of_range("map::at: key not found");
}

template <typename Key, typename T, typename Compare, typename Allocator>
T &ft::map<Key, T, Compare, Allocator>::operator[](const Key &key)
{
	node_type *node = this->tree.getRoot();
	key_compare comp;

	while (node != NULL)
	{
		if (comp(key, node->value.first))
		{
			node = node->left;
		}
		else if (comp(node->value.first, key))
		{
			node = node->right;
		}
		else // found the key
		{
			return node->value.second;
		}
	}
	return this->tree.insert(
		value_type(key, T())
	).first->second;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator
ft::map<Key, T, Compare, Allocator>::begin()
{
	return this->tree.begin();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator
ft::map<Key, T, Compare, Allocator>::begin() const
{
	return this->tree.begin();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator
ft::map<Key, T, Compare, Allocator>::end()
{
	return this->tree.end();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator
ft::map<Key, T, Compare, Allocator>::end() const
{
	return this->tree.end();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::reverse_iterator
ft::map<Key, T, Compare, Allocator>::rbegin()
{
	return reverse_iterator(this->tree.end());
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator
ft::map<Key, T, Compare, Allocator>::rbegin() const
{
	return const_reverse_iterator(this->tree.end());
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::reverse_iterator
ft::map<Key, T, Compare, Allocator>::rend()
{
	return reverse_iterator(this->tree.begin());
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator
ft::map<Key, T, Compare, Allocator>::rend() const
{
	return const_reverse_iterator(this->tree.begin());
}
