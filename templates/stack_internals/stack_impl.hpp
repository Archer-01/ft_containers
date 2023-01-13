#pragma once

#include "../stack.hpp"

template <typename T, typename Container>
ft::stack<T, Container>::stack(const container_type &cont) : c(cont) {}

template <typename T, typename Container>
ft::stack<T, Container>::stack(const stack &other) : c(other.c) {}

template <typename T, typename Container>
ft::stack<T, Container>::~stack() { (void) this; }

template <typename T, typename Container>
ft::stack<T, Container> &ft::stack<T, Container>::operator=(const stack &other)
{
	if (this != &other)
	{
		this->c = other.c;
	}
	return *this;
}

template <typename T, typename Container>
typename ft::stack<T, Container>::reference ft::stack<T, Container>::top()
{
	return this->c.back();
}

template <typename T, typename Container>
typename ft::stack<T, Container>::const_reference
ft::stack<T, Container>::top() const
{
	return this->c.back();
}

template <typename T, typename Container>
bool ft::stack<T, Container>::empty() const
{
	return this->c.empty();
}

template <typename T, typename Container>
typename ft::stack<T, Container>::size_type
ft::stack<T, Container>::size() const
{
	return this->c.size();
}

template <typename T, typename Container>
void ft::stack<T, Container>::push(const value_type &value)
{
	this->c.push_back(value);
}

template <typename T, typename Container>
void ft::stack<T, Container>::pop()
{
	this->c.pop_back();
}

template <typename T, typename Container>
bool ft::operator==(
	const ft::stack<T, Container> &lhs,
	const ft::stack<T, Container> &rhs
)
{
	return lhs.c == rhs.c;
}

template <typename T, typename Container>
bool ft::operator!=(
	const ft::stack<T, Container> &lhs,
	const ft::stack<T, Container> &rhs
)
{
	return lhs.c != rhs.c;
}

template <typename T, typename Container>
bool ft::operator<(
	const ft::stack<T, Container> &lhs,
	const ft::stack<T, Container> &rhs
)
{
	return lhs.c < rhs.c;
}

template <typename T, typename Container>
bool ft::operator<=(
	const ft::stack<T, Container> &lhs,
	const ft::stack<T, Container> &rhs
)
{
	return lhs.c <= rhs.c;
}

template <typename T, typename Container>
bool ft::operator>(
	const ft::stack<T, Container> &lhs,
	const ft::stack<T, Container> &rhs
)
{
	return lhs.c > rhs.c;
}

template <typename T, typename Container>
bool ft::operator>=(
	const ft::stack<T, Container> &lhs,
	const ft::stack<T, Container> &rhs
)
{
	return lhs.c >= rhs.c;
}
