#pragma once

#include "map.hpp"

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>::map() : _tree(Allocator(), value_compare(Compare())), _size(0) {}

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>::map(
	const Compare &comp,
	const Allocator &alloc
) : _tree(value_compare(comp), alloc), _size(0) {}

template <typename Key, typename T, typename Compare, typename Allocator>
template <typename InputIterator>
ft::map<Key, T, Compare, Allocator>::map(
	InputIterator first,
	InputIterator last,
	const Compare &comp,
	const Allocator &alloc
) : _tree(value_compare(comp), alloc), _size(0)
{
	#pragma unroll
	while (first != last)
	{
		this->insert(*first);
		++first;
	}
}

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>::map(const map &other) : _tree(other.tree), _size(other.size) {}

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>::~map() { (void) this; }

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>&
ft::map<Key, T, Compare, Allocator>::operator=(const map &other)
{
	if (this != &other)
	{
		this->_tree = other._tree;
		this->_size = other._size;
	}
	return *this;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::allocator_type
ft::map<Key, T, Compare, Allocator>::get_allocator() const
{
	return this->_tree.getAllocator();
}

template <typename Key, typename T, typename Compare, typename Allocator>
T &ft::map<Key, T, Compare, Allocator>::at(const Key &key)
{
	node_type *node = this->_tree.getRoot();
	key_compare comp;

	#pragma unroll
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
	node_type *node = this->_tree.getRoot();
	key_compare comp;

	#pragma unroll
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
	node_type *node = this->_tree.getRoot();
	key_compare comp;

	#pragma unroll
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
	return this->insert(
		value_type(key, T())
	).first->second;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator
ft::map<Key, T, Compare, Allocator>::begin()
{
	return this->_tree.begin();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator
ft::map<Key, T, Compare, Allocator>::begin() const
{
	return this->_tree.begin();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator
ft::map<Key, T, Compare, Allocator>::end()
{
	return this->_tree.end();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator
ft::map<Key, T, Compare, Allocator>::end() const
{
	return this->_tree.end();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::reverse_iterator
ft::map<Key, T, Compare, Allocator>::rbegin()
{
	return reverse_iterator(this->_tree.end());
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator
ft::map<Key, T, Compare, Allocator>::rbegin() const
{
	return const_reverse_iterator(this->_tree.end());
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::reverse_iterator
ft::map<Key, T, Compare, Allocator>::rend()
{
	return reverse_iterator(this->_tree.begin());
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator
ft::map<Key, T, Compare, Allocator>::rend() const
{
	return const_reverse_iterator(this->_tree.begin());
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool ft::map<Key, T, Compare, Allocator>::empty() const
{
	return this->_size == 0;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type 
ft::map<Key, T, Compare, Allocator>::size() const
{
	return this->_size;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type
ft::map<Key, T, Compare, Allocator>::max_size() const
{
	return this->_tree.getAllocator().max_size();
}

template <typename Key, typename T, typename Compare, typename Allocator>
void ft::map<Key, T, Compare, Allocator>::clear()
{
	this->_tree.clear();
	this->_size = 0;
}

template <typename Key, typename T, typename Compare, typename Allocator>
ft::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, bool>
ft::map<Key, T, Compare, Allocator>::insert(const value_type &value)
{
	ft::pair<iterator, bool> result;

	result = this->_tree.insert(value);
	if (result.second == true)
	{
		++this->_size;
	}
	return result;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator
ft::map<Key, T, Compare, Allocator>::insert(
	iterator position,
	const value_type &value
)
{
	++this->_size;
	return this->_tree.insertAt(position, value);
}

template <typename Key, typename T, typename Compare, typename Allocator>
template <typename InputIterator>
void ft::map<Key, T, Compare, Allocator>::insert(
	InputIterator first,
	InputIterator last
)
{
	#pragma unroll
	while (first != last)
	{
		this->insert(*first);
		++first;
	}
}
