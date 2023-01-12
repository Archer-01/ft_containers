#pragma once

#include "algorithm.hpp"
#include "map.hpp"

template <typename Key, typename T, typename Compare, typename Allocator>
ft::map<Key, T, Compare, Allocator>::map() : _tree(value_compare(Compare()), Allocator()), _size(0) {}

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
ft::map<Key, T, Compare, Allocator>::map(const map &other) : _tree(other._tree), _size(other._size) {}

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
	ft::pair<iterator, bool> result;

	result = this->_tree.insertAt(position, value);
	if (result.second == true)
	{
		++this->_size;
	}
	return result.first;
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

template <typename Key, typename T, typename Compare, typename Allocator>
void ft::map<Key, T, Compare, Allocator>::erase(iterator position)
{
	try
	{
		this->at(position->first);
		this->_tree.erase(position.getCurrent());
		--this->_size;
	}
	catch (const std::out_of_range &exception) {}
}

template <typename Key, typename T, typename Compare, typename Allocator>
void ft::map<Key, T, Compare, Allocator>::erase(iterator first, iterator last)
{
	#pragma unroll
	while (first != last)
	{
		iterator tmp = first;

		++first;
		this->erase(tmp);
	}
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type
ft::map<Key, T, Compare, Allocator>::erase(const Key &key)
{
	node_type *node = this->_tree.getRoot();
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
		else // Found the key
		{
			break;
		}
	}

	if (node == NULL)
	{
		return 0;
	}
	this->_tree.erase(node);
	--this->_size;
	return 1;
}

template <typename Key, typename T, typename Compare, typename Allocator>
void ft::map<Key, T, Compare, Allocator>::swap(map &other)
{
	std::swap(this->_tree, other._tree);
	std::swap(this->_size, other._size);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type
ft::map<Key, T, Compare, Allocator>::count(const Key &key) const
{
	try
	{
		this->at(key);
		return 1;
	}
	catch (const std::out_of_range &exception)
	{
		return 0;
	}
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator
ft::map<Key, T, Compare, Allocator>::find(const Key &key)
{
	node_type *root = this->_tree.getRoot();
	node_type *node = root;
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
		else // Found the key
		{
			return iterator(node, root);
		}
	}
	return this->end();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator
ft::map<Key, T, Compare, Allocator>::find(const Key &key) const
{
	node_type *root = this->_tree.getRoot();
	node_type *node = root;
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
		else // Found the key
		{
			return const_iterator(node, root);
		}
	}
	return this->end();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator
ft::map<Key, T, Compare, Allocator>::lower_bound(const Key &key)
{
	node_type *root = this->_tree.getRoot();
	node_type *node = root;
	node_type *result = NULL;
	key_compare comp;

	while (node != NULL)
	{
		if (not comp(key, node->value.first))
		{
			result = node;
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}
	return iterator(result, root);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator
ft::map<Key, T, Compare, Allocator>::lower_bound(const Key &key) const
{
	node_type *root = this->_tree.getRoot();
	node_type *node = root;
	node_type *result = NULL;
	key_compare comp;

	while (node != NULL)
	{
		if (not comp(key, node->value.first))
		{
			result = node;
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}
	return const_iterator(result, root);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator
ft::map<Key, T, Compare, Allocator>::upper_bound(const Key &key)
{
	node_type *root = this->_tree.getRoot();
	node_type *node = root;
	node_type *result = NULL;
	key_compare comp;

	while (node != NULL)
	{
		if (comp(key, node->value.first))
		{
			result = node;
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}
	return iterator(result, root);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator
ft::map<Key, T, Compare, Allocator>::upper_bound(const Key &key) const
{
	node_type *root = this->_tree.getRoot();
	node_type *node = root;
	node_type *result = NULL;
	key_compare comp;

	while (node != NULL)
	{
		if (comp(key, node->value.first))
		{
			result = node;
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}
	return const_iterator(result, root);
}

template <typename Key, typename T, typename Compare, typename Allocator>
ft::pair<
	typename ft::map<Key, T, Compare, Allocator>::iterator,
	typename ft::map<Key, T, Compare, Allocator>::iterator
>
ft::map<Key, T, Compare, Allocator>::equal_range(const Key &key)
{
	return ft::make_pair(
		this->lower_bound(key),
		this->upper_bound(key)
	);
}

template <typename Key, typename T, typename Compare, typename Allocator>
ft::pair<
	typename ft::map<Key, T, Compare, Allocator>::const_iterator,
	typename ft::map<Key, T, Compare, Allocator>::const_iterator
>
ft::map<Key, T, Compare, Allocator>::equal_range(const Key &key) const
{
	return ft::make_pair(
		this->lower_bound(key),
		this->upper_bound(key)
	);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::key_compare
ft::map<Key, T, Compare, Allocator>::key_comp() const
{
	return key_compare();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::value_compare
ft::map<Key, T, Compare, Allocator>::value_comp() const
{
	return this->_tree.getCompare();
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool ft::operator==(
	const ft::map<Key, T, Compare, Allocator> &lhs,
	const ft::map<Key, T, Compare, Allocator> &rhs
)
{
	return (
		lhs.size() == rhs.size()
		and ft::equal(lhs.begin(), lhs.end(), rhs.begin())
	);
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool ft::operator!=(
	const ft::map<Key, T, Compare, Allocator> &lhs,
	const ft::map<Key, T, Compare, Allocator> &rhs
)
{
	return not (lhs == rhs);
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool ft::operator<(
	const ft::map<Key, T, Compare, Allocator> &lhs,
	const ft::map<Key, T, Compare, Allocator> &rhs
)
{
	return ft::lexicographical_compare(
		lhs.begin(),
		lhs.end(),
		rhs.begin(),
		rhs.end(),
		lhs.value_comp()
	);
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool ft::operator<=(
	const ft::map<Key, T, Compare, Allocator> &lhs,
	const ft::map<Key, T, Compare, Allocator> &rhs
)
{
	return lhs < rhs or lhs == rhs;
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool ft::operator>(
	const ft::map<Key, T, Compare, Allocator> &lhs,
	const ft::map<Key, T, Compare, Allocator> &rhs
)
{
	return not (lhs <= rhs);
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool ft::operator>=(
	const ft::map<Key, T, Compare, Allocator> &lhs,
	const ft::map<Key, T, Compare, Allocator> &rhs
)
{
	return not (lhs < rhs);
}

template <typename Key, typename T, typename Compare, typename Allocator>
void ft::swap(
	const ft::map<Key, T, Compare, Allocator> &lhs,
	const ft::map<Key, T, Compare, Allocator> &rhs
)
{
	lhs.swap(rhs);
}
