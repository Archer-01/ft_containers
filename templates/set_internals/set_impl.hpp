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

template <typename Key, typename Compare, typename Allocator>
typename ft::set<Key, Compare, Allocator>::iterator
ft::set<Key, Compare, Allocator>::begin()
{
	return this->_tree.begin();
}

template <typename Key, typename Compare, typename Allocator>
typename ft::set<Key, Compare, Allocator>::const_iterator
ft::set<Key, Compare, Allocator>::begin() const
{
	return this->_tree.begin();
}

template <typename Key, typename Compare, typename Allocator>
typename ft::set<Key, Compare, Allocator>::iterator
ft::set<Key, Compare, Allocator>::end()
{
	return this->_tree.end();
}

template <typename Key, typename Compare, typename Allocator>
typename ft::set<Key, Compare, Allocator>::const_iterator
ft::set<Key, Compare, Allocator>::end() const
{
	return this->_tree.end();
}

template <typename Key, typename Compare, typename Allocator>
typename ft::set<Key, Compare, Allocator>::reverse_iterator
ft::set<Key, Compare, Allocator>::rbegin()
{
	return reverse_iterator(this->end());
}

template <typename Key, typename Compare, typename Allocator>
typename ft::set<Key, Compare, Allocator>::const_reverse_iterator
ft::set<Key, Compare, Allocator>::rbegin() const
{
	return const_reverse_iterator(this->end());
}

template <typename Key, typename Compare, typename Allocator>
typename ft::set<Key, Compare, Allocator>::reverse_iterator
ft::set<Key, Compare, Allocator>::rend()
{
	return reverse_iterator(this->begin());
}

template <typename Key, typename Compare, typename Allocator>
typename ft::set<Key, Compare, Allocator>::const_reverse_iterator
ft::set<Key, Compare, Allocator>::rend() const
{
	return const_reverse_iterator(this->begin());
}
