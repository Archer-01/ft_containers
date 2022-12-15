#pragma once

#include "random_access_iterator.hpp"

template <typename T>
ft::random_access_iterator<T>::random_access_iterator()
{
	m_Current = NULL;
}

template <typename T>
template <typename U>
ft::random_access_iterator<T>::random_access_iterator(
	const random_access_iterator<U> &rhs
)
{
	m_Current = rhs.base();
}

template <typename T>
ft::random_access_iterator<T>::random_access_iterator(pointer ptr)
{
	m_Current = ptr;
}

template <typename T>
template <typename U>
ft::random_access_iterator<T>& ft::random_access_iterator<T>::operator=(
	const random_access_iterator<U> &rhs
)
{
	if (this != &rhs)
	{
		m_Current = rhs.base();
	}
	return (*this);
}

template <typename T>
template <typename U>
bool ft::random_access_iterator<T>::operator==(
	const random_access_iterator<U> &rhs
) const
{
	return m_Current == rhs.base();
}

template <typename T>
template <typename U>
bool ft::random_access_iterator<T>::operator!=(
	const random_access_iterator<U> &rhs
) const
{
	return m_Current != rhs.base();
}

template <typename T>
template <typename U>
bool ft::random_access_iterator<T>::operator<(
	const random_access_iterator<U> &rhs
) const
{
	return m_Current < rhs.base();
}

template <typename T>
template <typename U>
bool ft::random_access_iterator<T>::operator<=(
	const random_access_iterator<U> &rhs
) const
{
	return m_Current <= rhs.base();
}

template <typename T>
template <typename U>
bool ft::random_access_iterator<T>::operator>(
	const random_access_iterator<U> &rhs
) const
{
	return m_Current > rhs.base();
}

template <typename T>
template <typename U>
bool ft::random_access_iterator<T>::operator>=(
	const random_access_iterator<U> &rhs
) const
{
	return m_Current >= rhs.base();
}

template <typename T>
typename ft::random_access_iterator<T>::reference
ft::random_access_iterator<T>::operator*() const
{
	return *m_Current;
}

template <typename T>
typename ft::random_access_iterator<T>::pointer
ft::random_access_iterator<T>::operator->() const
{
	return m_Current;
}

template <typename T>
typename ft::random_access_iterator<T>::reference
ft::random_access_iterator<T>::operator[](difference_type n) const
{
	return m_Current[n];
}

template <typename T>
ft::random_access_iterator<T>& ft::random_access_iterator<T>::operator++()
{
	++m_Current;
	return (*this);
}

template <typename T>
ft::random_access_iterator<T> ft::random_access_iterator<T>::operator++(int)
{
	random_access_iterator<T> tmp = *this;

	++m_Current;
	return tmp;
}

template <typename T>
ft::random_access_iterator<T>& ft::random_access_iterator<T>::operator--()
{
	--m_Current;
	return (*this);
}

template <typename T>
ft::random_access_iterator<T> ft::random_access_iterator<T>::operator--(int)
{
	random_access_iterator<T> tmp = *this;

	--m_Current;
	return tmp;
}

template <typename T>
ft::random_access_iterator<T> ft::random_access_iterator<T>::operator+(
	typename ft::random_access_iterator<T>::difference_type n
) const
{
	return random_access_iterator<T>(m_Current + n);
}

template <typename T>
ft::random_access_iterator<T> ft::random_access_iterator<T>::operator-(
	typename ft::random_access_iterator<T>::difference_type n
) const
{
	return random_access_iterator<T>(m_Current - n);
}

template <typename T>
ft::random_access_iterator<T> operator+(
	typename ft::random_access_iterator<T>::difference_type n,
	const ft::random_access_iterator<T> &rhs
)
{
	return rhs + n;
}

template <typename T>
typename ft::random_access_iterator<T>::difference_type
ft::random_access_iterator<T>::operator-(
	const random_access_iterator &rhs
) const
{
	return m_Current - rhs.m_Current;
}

template <typename T>
ft::random_access_iterator<T>& ft::random_access_iterator<T>::operator+=(
	typename ft::random_access_iterator<T>::difference_type n
)
{
	m_Current += n;
	return (*this);
}

template <typename T>
ft::random_access_iterator<T>& ft::random_access_iterator<T>::operator-=(
	typename ft::random_access_iterator<T>::difference_type n
)
{
	m_Current -= n;
	return (*this);
}

template <typename T>
typename ft::random_access_iterator<T>::pointer
ft::random_access_iterator<T>::base() const
{
	return m_Current;
}
