#pragma once

#include "../algorithm.hpp"
#include "../type_traits.hpp"
#include "../vector.hpp"
#include <cstddef>
#include <iterator>
#include <stdexcept>

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
	if (m_Data != NULL)
	{
		this->clear();
		m_Allocator.deallocate(m_Data, m_Capacity);
	}
}

template <typename T, typename Allocator>
ft::vector<T, Allocator>& ft::vector<T, Allocator>::operator=(const vector& other)
{
	if (this != &other)
	{
		this->clear();
		m_Allocator.deallocate(m_Data, m_Capacity);
		m_Allocator = other.m_Allocator;
		m_Capacity = other.m_Capacity;
		m_Data = m_Allocator.allocate(m_Capacity);
		#pragma unroll
		for (size_type i = 0; i < other.m_Size; ++i)
		{
			try
			{
				m_Allocator.construct(m_Data + i, other.m_Data[i]);
				++m_Size;
			}
			catch(...)
			{
				this->clear();
				m_Allocator.deallocate(m_Data, m_Capacity);
				m_Data = NULL;
				m_Capacity = 0;
				throw;
			}
		}
	}
	return *this;
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::assign(size_type count, const T& value)
{
	this->clear();
	this->reserve(count);
	#pragma unroll
	for (size_type i = 0; i < count; ++i)
	{
		this->push_back(value);
	}
}

template <typename T, typename Allocator>
template <typename InputIterator>
void ft::vector<T, Allocator>::assign(
	InputIterator first,
	typename ft::enable_if<
		not ft::is_integral<InputIterator>::value,
		InputIterator
	>::type last
)
{
	this->clear();
	this->reserve(std::distance(first, last));
	#pragma unroll
	for (InputIterator it = first; it != last; ++it)
	{
		this->push_back(*it);
	}
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::allocator_type
ft::vector<T, Allocator>::get_allocator() const
{
	return m_Allocator;
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference
ft::vector<T, Allocator>::at(size_type pos)
{
	if (pos >= m_Size)
	{
		throw std::out_of_range("vector::at");
	}
	return m_Data[pos];
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference
ft::vector<T, Allocator>::at(size_type pos) const
{
	if (pos >= m_Size)
	{
		throw std::out_of_range("vector::at");
	}
	return m_Data[pos];
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference
ft::vector<T, Allocator>::operator[](size_type pos)
{
	return m_Data[pos];
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference
ft::vector<T, Allocator>::operator[](size_type pos) const
{
	return m_Data[pos];
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference
ft::vector<T, Allocator>::front()
{
	return m_Data[0];
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference
ft::vector<T, Allocator>::front() const
{
	return m_Data[0];
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reference
ft::vector<T, Allocator>::back()
{
	return m_Data[m_Size - 1];
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reference
ft::vector<T, Allocator>::back() const
{
	return m_Data[m_Size - 1];
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::pointer
ft::vector<T, Allocator>::data()
{
	return m_Data;
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_pointer
ft::vector<T, Allocator>::data() const
{
	return m_Data;
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::begin()
{
	return iterator(m_Data);
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_iterator
ft::vector<T, Allocator>::begin() const
{
	return const_iterator(m_Data);
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::end()
{
	return iterator(m_Data + m_Size);
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_iterator
ft::vector<T, Allocator>::end() const
{
	return const_iterator(m_Data + m_Size);
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reverse_iterator
ft::vector<T, Allocator>::rbegin()
{
	return reverse_iterator(this->end());
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator
ft::vector<T, Allocator>::rbegin() const
{
	return const_reverse_iterator(this->end());
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::reverse_iterator
ft::vector<T, Allocator>::rend()
{
	return reverse_iterator(this->begin());
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator
ft::vector<T, Allocator>::rend() const
{
	return const_reverse_iterator(this->begin());
}

template <typename T, typename Allocator>
bool ft::vector<T, Allocator>::empty() const
{
	return m_Size == 0;
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::size_type
ft::vector<T, Allocator>::size() const
{
	return m_Size;
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::size_type
ft::vector<T, Allocator>::max_size() const
{
	return m_Allocator.max_size();
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::reserve(size_type new_cap)
{
	if (new_cap > m_Capacity)
	{
		pointer new_data;

		new_data = m_Allocator.allocate(new_cap);
		#pragma unroll
		for (size_type i = 0; i < m_Size; ++i)
		{
			m_Allocator.construct(&new_data[i], m_Data[i]);
			m_Allocator.destroy(&m_Data[i]);
		}
		m_Allocator.deallocate(m_Data, m_Capacity);
		m_Data = new_data;
		m_Capacity = new_cap;
	}
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::size_type
ft::vector<T, Allocator>::capacity() const
{
	return m_Capacity;
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::clear()
{
	#pragma unroll
	for (size_type i = 0; i < m_Size; ++i)
	{
		m_Allocator.destroy(&m_Data[i]);
	}
	m_Size = 0;
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator
ft::vector<T, Allocator>::insert(const_iterator pos, const T& value)
{
	size_type index = pos - this->begin();
	size_type new_size = m_Size + 1;

	if (new_size > m_Capacity)
	{
		size_type new_capacity = m_Capacity * 2;

		if (new_capacity < new_size)
		{
			new_capacity = new_size;
		}
		this->reserve(new_capacity);
	}
	#pragma unroll
	for (size_type i = m_Size; i > index; --i)
	{
		m_Allocator.construct(&m_Data[i], m_Data[i - 1]);
		m_Allocator.destroy(&m_Data[i - 1]);
	}
	try
	{
		m_Allocator.construct(&m_Data[index], value);
	}
	catch (...)
	{
		this->clear();
		m_Allocator.deallocate(m_Data, m_Capacity);
		m_Data = NULL;
		m_Capacity = 0;
		throw;
	}
	m_Size = new_size;
	return iterator(m_Data + index);
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator
ft::vector<T, Allocator>::insert(
	const_iterator pos,
	size_type count,
	const T& value
)
{
	size_type index = pos - this->begin();
	size_type new_size = m_Size + count;

	if (new_size > m_Capacity)
	{
		size_type new_capacity = m_Capacity * 2;

		if (new_capacity < new_size)
		{
			new_capacity = new_size;
		}
		this->reserve(new_capacity);
	}
	#pragma unroll
	for (size_type i = m_Size; i > index; --i)
	{
		m_Allocator.construct(&m_Data[i + count - 1], m_Data[i - 1]);
		m_Allocator.destroy(&m_Data[i - 1]);
	}
	#pragma unroll
	for (size_type i = 0; i < count; ++i)
	{
		try
		{
			m_Allocator.construct(&m_Data[index + i], value);
			++m_Size;
		}
		catch (...)
		{
			this->clear();
			m_Allocator.deallocate(m_Data, m_Capacity);
			m_Data = NULL;
			m_Capacity = 0;
			throw;
		}
	}
	return iterator(m_Data + index);
}

template <typename T, typename Allocator>
template <typename InputIterator>
typename ft::vector<T, Allocator>::iterator
ft::vector<T, Allocator>::insert(
	const_iterator pos,
	InputIterator first,
	typename ft::enable_if<
		not ft::is_integral<InputIterator>::value,
		InputIterator
	>::type last
)
{
	size_type index = pos - this->begin();
	size_type count = std::distance(first, last);
	size_type new_size = m_Size + count;

	if (new_size > m_Capacity)
	{
		size_type new_capacity = m_Capacity * 2;

		if (new_capacity < new_size)
		{
			new_capacity = new_size;
		}
		this->reserve(new_capacity);
	}
	#pragma unroll
	for (size_type i = m_Size; i > index; --i)
	{
		m_Allocator.construct(&m_Data[i + count - 1], m_Data[i - 1]);
		m_Allocator.destroy(&m_Data[i - 1]);
	}

	int i = 0;

	while (first != last)
	{
		try
		{
			m_Allocator.construct(&m_Data[index + i], *first);
			++m_Size;
			++first;
			++i;
		}
		catch (...)
		{
			this->clear();
			m_Allocator.deallocate(m_Data, m_Capacity);
			m_Data = NULL;
			m_Capacity = 0;
			throw;
		}
	}
	return iterator(m_Data + index);
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator
ft::vector<T, Allocator>::erase(const_iterator pos)
{
	size_type index = pos - this->begin();

	m_Allocator.destroy(&m_Data[index]);
	#pragma unroll
	for (size_type i = index; i < m_Size - 1; ++i)
	{
		m_Allocator.construct(&m_Data[i], m_Data[i + 1]);
		m_Allocator.destroy(&m_Data[i + 1]);
	}
	--m_Size;
	return iterator(m_Data + index);
}

template <typename T, typename Allocator>
typename ft::vector<T, Allocator>::iterator
ft::vector<T, Allocator>::erase(iterator first, iterator last)
{
	size_type index = first - this->begin();
	size_type count = last - first;

	#pragma unroll
	for (size_type i = index; i < index + count; ++i)
	{
		m_Allocator.destroy(&m_Data[i]);
	}
	#pragma unroll
	for (size_type i = index; i < m_Size - count; ++i)
	{
		m_Allocator.construct(&m_Data[i], m_Data[i + count]);
		m_Allocator.destroy(&m_Data[i + count]);
	}
	m_Size -= count;
	return iterator(m_Data + index);
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::push_back(const T& value)
{
	if (m_Size == m_Capacity)
	{
		if (m_Capacity == 0)
		{
			this->reserve(1);
		}
		else // m_Capacity != 0
		{
			this->reserve(m_Capacity * 2);
		}
	}
	try
	{
		m_Allocator.construct(&m_Data[m_Size], value);
	}
	catch (...)
	{
		this->clear();
		m_Allocator.deallocate(m_Data, m_Capacity);
		m_Data = NULL;
		m_Capacity = 0;
		throw;
	}
	++m_Size;
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::pop_back()
{
	m_Allocator.destroy(&m_Data[m_Size - 1]);
	--m_Size;
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::resize(size_type count, T value)
{
	if (count > m_Size)
	{
		if (count > m_Capacity)
		{
			size_type new_capacity = m_Capacity * 2;

			if (count > new_capacity)
			{
				new_capacity = count;
			}
			this->reserve(new_capacity);
		}
		#pragma unroll
		for (size_type i = m_Size; i < count; ++i)
		{
			try
			{
				m_Allocator.construct(&m_Data[i], value);
				++m_Size;
			}
			catch (...)
			{
				this->clear();
				m_Allocator.deallocate(m_Data, m_Capacity);
				m_Data = NULL;
				m_Capacity = 0;
				throw;
			}
		}
	}
	else // count <= m_Size
	{
		#pragma unroll
		for (size_type i = m_Size; i > count; --i)
		{
			m_Allocator.destroy(&m_Data[i - 1]);
		}
		m_Size = count;
	}
}

template <typename T, typename Allocator>
void ft::vector<T, Allocator>::swap(vector& other)
{
	std::swap(m_Data, other.m_Data);
	std::swap(m_Size, other.m_Size);
	std::swap(m_Capacity, other.m_Capacity);
	std::swap(m_Allocator, other.m_Allocator);
}

template <typename T, typename Allocator>
bool ft::operator==(
	const ft::vector<T, Allocator>& lhs,
	const ft::vector<T, Allocator>& rhs
)
{
	if (lhs.size() != rhs.size())
	{
		return false;
	}
	#pragma unroll
	for (size_t i = 0; i < lhs.size(); ++i)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
	}
	return true;
}

template <typename T, typename Allocator>
bool ft::operator!=(
	const ft::vector<T, Allocator>& lhs,
	const ft::vector<T, Allocator>& rhs
)
{
	return not (lhs == rhs);
}

template <typename T, typename Allocator>
bool ft::operator<(
	const ft::vector<T, Allocator>& lhs,
	const ft::vector<T, Allocator>& rhs
)
{
	return ft::lexicographical_compare(
		lhs.begin(),
		lhs.end(),
		rhs.begin(),
		rhs.end()
	);
}

template <typename T, typename Allocator>
bool ft::operator<=(
	const ft::vector<T, Allocator>& lhs,
	const ft::vector<T, Allocator>& rhs
)
{
	return (lhs < rhs) or (lhs == rhs);
}

template <typename T, typename Allocator>
bool ft::operator>(
	const ft::vector<T, Allocator>& lhs,
	const ft::vector<T, Allocator>& rhs
)
{
	return not (lhs <= rhs);
}

template <typename T, typename Allocator>
bool ft::operator>=(
	const ft::vector<T, Allocator>& lhs,
	const ft::vector<T, Allocator>& rhs
)
{
	return not (lhs < rhs);
}

template <typename T, typename Allocator>
void ft::swap(
	ft::vector<T, Allocator>& lhs,
	ft::vector<T, Allocator>& rhs
)
{
	lhs.swap(rhs);
}
