#pragma once

#include "set.hpp"

template <typename Key, typename Compare, typename Allocator>
ft::set<Key, Compare, Allocator>::set() : _tree(key_compare(), allocator_type()), _size(0) {}

template <typename Key, typename Compare, typename Allocator>
ft::set<Key, Compare, Allocator>::set(
	const key_compare &comp,
	const allocator_type &alloc
) : _tree(comp, alloc), _size(0) {}

template <typename Key, typename Compare, typename Allocator>
template <typename InputIterator>
ft::set<Key, Compare, Allocator>::set(
	InputIterator first,
	InputIterator last,
	const key_compare &comp,
	const allocator_type &alloc
) : _tree(comp, alloc), _size(0)
{
	while (first != last)
	{
		// TODO: Replace this with set::insert
		this->_tree.insert(*first);
		++first;
	}
}

template <typename Key, typename Compare, typename Allocator>
ft::set<Key, Compare, Allocator>::set(const set &other) : _tree(other._tree), _size(other._size) {}

template <typename Key, typename Compare, typename Allocator>
ft::set<Key, Compare, Allocator>::~set() { (void) this; }

template <typename Key, typename Compare, typename Allocator>
ft::set<Key, Compare, Allocator>&
ft::set<Key, Compare, Allocator>::operator=(const set &other)
{
	if (this != &other)
	{
		this->_size = other._size;
		this->_tree = other._tree;
	}
	return *this;
}

template <typename Key, typename Compare, typename Allocator>
typename ft::set<Key, Compare, Allocator>::allocator_type
ft::set<Key, Compare, Allocator>::get_allocator() const
{
	return this->_tree.get_allocator();
}
