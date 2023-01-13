#pragma once

#include "stack.hpp"

template <typename T, typename Container>
ft::stack<T, Container>::stack(const container_type &cont) : c(cont) {}

template <typename T, typename Container>
ft::stack<T, Container>::stack(const stack &other) : c(other._container) {}

template <typename T, typename Container>
ft::stack<T, Container>::~stack() { (void) this; }

template <typename T, typename Container>
ft::stack<T, Container> &ft::stack<T, Container>::operator=(const stack &other)
{
	if (this != &other)
	{
		this->_container = other._container;
	}
	return *this;
}
