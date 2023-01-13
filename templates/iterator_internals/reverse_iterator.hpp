#pragma once

#include "../iterator.hpp"

template <typename Iterator>
class ft::reverse_iterator
{
  public:
	typedef Iterator iterator_type;
	typedef
		typename iterator_traits<Iterator>::iterator_category iterator_category;
	typedef typename iterator_traits<Iterator>::value_type value_type;
	typedef typename iterator_traits<Iterator>::difference_type difference_type;
	typedef typename iterator_traits<Iterator>::pointer pointer;
	typedef typename iterator_traits<Iterator>::reference reference;

	reverse_iterator();
	explicit reverse_iterator(iterator_type iter);
	template <typename Iter>
	reverse_iterator(const reverse_iterator<Iter> &rev_it);

	template <typename Iter>
	reverse_iterator &operator=(const reverse_iterator<Iter> &rev_it);

	iterator_type base() const;

	reference operator*() const;
	pointer operator->() const;

	reference operator[](difference_type n) const;

	reverse_iterator &operator++();
	reverse_iterator &operator--();
	reverse_iterator operator++(int);
	reverse_iterator operator--(int);
	reverse_iterator operator+(difference_type n) const;
	reverse_iterator operator-(difference_type n) const;
	reverse_iterator &operator+=(difference_type n);
	reverse_iterator &operator-=(difference_type n);

  protected:
	iterator_type current;
};

namespace ft
{

template <typename Iterator1, typename Iterator2>
bool operator==(const ft::reverse_iterator<Iterator1> &lhs,
				const ft::reverse_iterator<Iterator2> &rhs);

template <typename Iterator1, typename Iterator2>
bool operator!=(const ft::reverse_iterator<Iterator1> &lhs,
				const ft::reverse_iterator<Iterator2> &rhs);

template <typename Iterator1, typename Iterator2>
bool operator<(const ft::reverse_iterator<Iterator1> &lhs,
			   const ft::reverse_iterator<Iterator2> &rhs);

template <typename Iterator1, typename Iterator2>
bool operator<=(const ft::reverse_iterator<Iterator1> &lhs,
				const ft::reverse_iterator<Iterator2> &rhs);

template <typename Iterator1, typename Iterator2>
bool operator>(const ft::reverse_iterator<Iterator1> &lhs,
			   const ft::reverse_iterator<Iterator2> &rhs);

template <typename Iterator1, typename Iterator2>
bool operator>=(const ft::reverse_iterator<Iterator1> &lhs,
				const ft::reverse_iterator<Iterator2> &rhs);

template <typename Iterator>
ft::reverse_iterator<Iterator>
operator+(typename ft::reverse_iterator<Iterator>::difference_type n,
		  const ft::reverse_iterator<Iterator> &rev_it);

template <typename Iterator1, typename Iterator2>
typename ft::reverse_iterator<Iterator1>::difference_type
operator-(const ft::reverse_iterator<Iterator1> &lhs,
		  const ft::reverse_iterator<Iterator2> &rhs);

}; // namespace ft

#include "reverse_iterator_impl.hpp"
