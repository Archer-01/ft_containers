#pragma once

#include "pair.hpp"

template <typename T1, typename T2>
ft::pair<T1, T2>::pair()
{
	this->first = first_type();
	this->second = second_type();
}

template <typename T1, typename T2>
ft::pair<T1, T2>::pair(const T1& first, const T2& second)
{
	this->first = first;
	this->second = second;
}

template <typename T1, typename T2>
template <typename U1, typename U2>
ft::pair<T1, T2>::pair(const pair<U1, U2>& rhs)
{
	this->first = rhs.first;
	this->second = rhs.second;
}

template <typename T1, typename T2>
ft::pair<T1, T2>& ft::pair<T1, T2>::operator=(const pair& rhs)
{
	if (this != &rhs)
	{
		this->first = rhs.first;
		this->second = rhs.second;
	}
	return *this;
}

template <typename T1, typename T2>
bool ft::operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return (lhs.first == rhs.first) and (lhs.second == rhs.second);
}

template <typename T1, typename T2>
bool ft::operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return not (lhs == rhs);
}

template <typename T1, typename T2>
bool ft::operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	if (lhs.first < rhs.first)
	{
		return true;
	}
	if (rhs.first < lhs.first)
	{
		return false;
	}
	if (lhs.second < rhs.second)
	{
		return true;
	}
	return false;
}

template <typename T1, typename T2>
bool ft::operator<=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return not (rhs < lhs);
}

template <typename T1, typename T2>
bool ft::operator>(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return rhs < lhs;
}

template <typename T1, typename T2>
bool ft::operator>=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return not (lhs < rhs);
}

template <typename T1, typename T2>
ft::pair<T1, T2> ft::make_pair(T1 first, T2 second)
{
	return ft::pair<T1, T2>(first, second);
}
