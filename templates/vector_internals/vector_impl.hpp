#pragma once

#include "vector.hpp"
#include <cstddef>
#include <iterator>

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector()
{
	m_Data = NULL;
	m_Size = 0;
	m_Capacity = 0;
	m_Allocator = allocator_type();
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector(const Allocator& alloc)
{
	m_Data = NULL;
	m_Size = 0;
	m_Capacity = 0;
	m_Allocator = alloc;
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector(
	size_type count,
	const T& value,
	const Allocator& alloc
)
{
	m_Data = NULL;
	m_Size = 0;
	m_Capacity = 0;
	m_Allocator = alloc;
	this->assign(count, value);
}

template <typename T, typename Allocator>
template <typename InputIterator>
ft::vector<T, Allocator>::vector(
	InputIterator first,
	typename ft::enable_if<
		not ft::is_integral<InputIterator>::value,
		InputIterator
	>::type last,
	const Allocator& alloc
)
{
	m_Data = NULL;
	m_Size = 0;
	m_Capacity = 0;
	m_Allocator = alloc;
	this->assign(first, last);
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>::vector(const vector& other)
{
	m_Data = NULL;
	m_Size = 0;
	m_Capacity = 0;
	m_Allocator = other.m_Allocator;
	this->assign(other.begin(), other.end());
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>::~vector()
{
	this->clear();
	m_Allocator.deallocate(m_Data, m_Capacity);
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>& ft::vector<T, Allocator>::operator=(const vector& other)
{
	if (this != &other)
	{
		m_Allocator = other.m_Allocator;
		this->assign(other.begin(), other.end());
	}
	return *this;
}
