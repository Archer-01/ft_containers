#pragma once

#include "reverse_iterator.hpp"

template <typename Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator()
{
	this->current = iterator_type();
}

template <typename Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator(iterator_type iter)
{
	this->current = iter;
}

template <typename Iterator>
template <typename Iter>
ft::reverse_iterator<Iterator>::reverse_iterator(
	const reverse_iterator<Iter>& rev_it
)
{
	*this = rev_it;
}

template <typename Iterator>
template <typename Iter>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator=(
	const reverse_iterator<Iter>& rev_it
)
{
	if (this != &rev_it)
	{
		this->current = rev_it.base();
	}
	return *this;
}

template <typename Iterator>
Iterator ft::reverse_iterator<Iterator>::base() const
{
	return this->current;
}

template <typename Iterator>
typename ft::reverse_iterator<Iterator>::reference ft::reverse_iterator<Iterator>::operator*() const
{
	iterator_type tmp;

	tmp = this->current;
	--tmp;
	return *tmp;
}

template <typename Iterator>
typename ft::reverse_iterator<Iterator>::pointer ft::reverse_iterator<Iterator>::operator->() const
{
	return &(operator*());
}

template <typename Iterator>
typename ft::reverse_iterator<Iterator>::reference ft::reverse_iterator<Iterator>::operator[](
	difference_type n
) const
{
	return this->current[-n - 1];
}

template <typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator++()
{
	--this->current;
	return *this;
}

template <typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator--()
{
	++this->current;
	return *this;
}

template <typename Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator++(int)
{
	reverse_iterator tmp = *this;

	--this->current;
	return tmp;
}

template <typename Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator--(int)
{
	reverse_iterator tmp = *this;

	++this->current;
	return tmp;
}

template <typename Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator+(
	difference_type n
) const
{
	return reverse_iterator(this->current - n);
}

template <typename Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator-(
	difference_type n
) const
{
	return reverse_iterator(this->current + n);
}

template <typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator+=(
	difference_type n
)
{
	this->current -= n;
	return *this;
}

template <typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator-=(
	difference_type n
)
{
	this->current += n;
	return *this;
}

template <typename Iterator1, typename Iterator2>
bool ft::operator==(
	const reverse_iterator<Iterator1>& lhs,
	const reverse_iterator<Iterator2>& rhs
)
{
	return lhs.base() == rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool ft::operator!=(
	const reverse_iterator<Iterator1>& lhs,
	const reverse_iterator<Iterator2>& rhs
)
{
	return lhs.base() != rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool ft::operator<(
	const reverse_iterator<Iterator1>& lhs,
	const reverse_iterator<Iterator2>& rhs
)
{
	return lhs.base() > rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool ft::operator<=(
	const reverse_iterator<Iterator1>& lhs,
	const reverse_iterator<Iterator2>& rhs
)
{
	return lhs.base() >= rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool ft::operator>(
	const reverse_iterator<Iterator1>& lhs,
	const reverse_iterator<Iterator2>& rhs
)
{
	return lhs.base() < rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool ft::operator>=(
	const reverse_iterator<Iterator1>& lhs,
	const reverse_iterator<Iterator2>& rhs
)
{
	return lhs.base() <= rhs.base();
}

template <typename Iterator>
ft::reverse_iterator<Iterator> ft::operator+(
	typename reverse_iterator<Iterator>::difference_type n,
	const reverse_iterator<Iterator>& rev_it
)
{
	return rev_it + n;
}

template <typename Iterator1, typename Iterator2>
typename ft::reverse_iterator<Iterator1>::difference_type ft::operator-(
	const reverse_iterator<Iterator1>& lhs,
	const reverse_iterator<Iterator2>& rhs
)
{
	return rhs.base() - lhs.base();
}
