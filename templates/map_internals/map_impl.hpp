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
	InputIterator last,
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
	const_iterator iter = this->find(key);

	if (iter != this->end())
	{
		return iter->second;
	}
	throw std::out_of_range("map::at: key not found");
}

template <typename Key, typename T, typename Compare, typename Allocator>
T& ft::map<Key, T, Compare, Allocator>::operator[](const Key &key)
{
	const_iterator iter = this->find(key);

	if (iter != this->end())
	{
		return iter->second;
	}
	return m_Tree.insert(value_type(key, T())).first->second;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator
ft::map<Key, T, Compare, Allocator>::begin()
{
	return m_Tree.begin();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator
ft::map<Key, T, Compare, Allocator>::begin() const
{
	return m_Tree.begin();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator
ft::map<Key, T, Compare, Allocator>::end()
{
	return m_Tree.end();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator
ft::map<Key, T, Compare, Allocator>::end() const
{
	return m_Tree.end();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::reverse_iterator
ft::map<Key, T, Compare, Allocator>::rbegin()
{
	return ft::reverse_iterator<iterator>(this->end());
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator
ft::map<Key, T, Compare, Allocator>::rbegin() const
{
	return ft::reverse_iterator<const_iterator>(this->end());
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::reverse_iterator
ft::map<Key, T, Compare, Allocator>::rend()
{
	return ft::reverse_iterator<iterator>(this->begin());
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator
ft::map<Key, T, Compare, Allocator>::rend() const
{
	return ft::reverse_iterator<const_iterator>(this->begin());
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool ft::map<Key, T, Compare, Allocator>::empty() const
{
	return m_Tree.get_size() == 0;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type
ft::map<Key, T, Compare, Allocator>::size() const
{
	return m_Tree.get_size();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type
ft::map<Key, T, Compare, Allocator>::max_size() const
{
	return m_Tree.get_allocator().max_size();
}

template <typename Key, typename T, typename Compare, typename Allocator>
void ft::map<Key, T, Compare, Allocator>::clear()
{
	m_Tree.~tree_type();
}

template <typename Key, typename T, typename Compare, typename Allocator>
ft::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, bool>
ft::map<Key, T, Compare, Allocator>::insert(const value_type &val)
{
	return m_Tree.insert(val);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator
ft::map<Key, T, Compare, Allocator>::insert(iterator pos, const value_type &val)
{
	return m_Tree.insertAt(pos, val).first;
}

template <typename Key, typename T, typename Compare, typename Allocator>
template <typename InputIterator>
void ft::map<Key, T, Compare, Allocator>::insert(InputIterator first, InputIterator last)
{
	while (first != last)
	{
		m_Tree.insert(*first);
		++first;
	}
}

template <typename Key, typename T, typename Compare, typename Allocator>
void ft::map<Key, T, Compare, Allocator>::erase(iterator pos)
{
	m_Tree.erase(pos);
}

template <typename Key, typename T, typename Compare, typename Allocator>
void ft::map<Key, T, Compare, Allocator>::erase(iterator first, iterator last)
{
	while (first != last)
	{
		iterator tmp = first;

		++first;
		m_Tree.erase(tmp);
	}
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type
ft::map<Key, T, Compare, Allocator>::erase(const Key &key)
{
	iterator iter = this->find(key);

	if (iter != this->end())
	{
		this->erase(iter);
		return 1;
	}
	return 0;
}

template <typename Key, typename T, typename Compare, typename Allocator>
void ft::map<Key, T, Compare, Allocator>::swap(map &other)
{
	std::swap(this->m_Tree, other.m_Tree);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type
ft::map<Key, T, Compare, Allocator>::count(const Key &key) const
{
	return (this->find(key) != this->end()) ? 1 : 0;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator
ft::map<Key, T, Compare , Allocator>::find(const Key &key)
{
	typename tree_type::Node *root = this->m_Tree.get_root();
	typename tree_type::Node *node = root;
	Compare comp;

	while (node != NULL)
	{
		if (comp(key, node->data.first))
		{
			node = node->left;
		}
		else if (comp(node->data.first, key))
		{
			node = node->right;
		}
		else // key == node->data.first
		{
			return iterator(root, node);
		}
	}
	return this->end();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator
ft::map<Key, T, Compare, Allocator>::find(const Key &key) const
{
	typename tree_type::Node *root = this->m_Tree.get_root();
	typename tree_type::Node *node = root;
	Compare comp;

	while (node != NULL)
	{
		if (comp(key, node->data.first))
		{
			node = node->left;
		}
		else if (comp(node->data.first, key))
		{
			node = node->right;
		}
		else // key == node->data.first
		{
			return const_iterator(root, node);
		}
	}
	return this->end();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator
ft::map<Key, T, Compare, Allocator>::lower_bound(const Key &key)
{
	iterator iter = this->begin();
	Compare comp;

	while (iter != this->end() and comp(iter->first, key))
	{
		++iter;
	}
	return iter;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator
ft::map<Key, T, Compare, Allocator>::lower_bound(const Key &key) const
{
	const_iterator iter = this->begin();
	Compare comp;

	while (iter != this->end() and comp(iter->first, key))
	{
		++iter;
	}
	return iter;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator
ft::map<Key, T, Compare, Allocator>::upper_bound(const Key &key)
{
	iterator iter = this->begin();
	Compare comp;

	while (iter != this->end() and not comp(key, iter->first))
	{
		++iter;
	}
	return iter;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator
ft::map<Key, T, Compare, Allocator>::upper_bound(const Key &key) const
{
	const_iterator iter = this->begin();
	Compare comp;

	while (iter != this->end() and not comp(key, iter->first))
	{
		++iter;
	}
	return iter;
}
