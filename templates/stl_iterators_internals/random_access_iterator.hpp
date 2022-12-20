#pragma once

#include "stl_iterators.hpp"

template <typename T>
class ft::random_access_iterator
	: public std::iterator<std::random_access_iterator_tag, T>
{
	public:
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;

		random_access_iterator();
		template <typename U>
		random_access_iterator(const random_access_iterator<U> &rhs);

		template <typename U>
		random_access_iterator& operator=(const random_access_iterator<U> &rhs);

		random_access_iterator(pointer ptr);

		template <typename U>
		bool operator==(const random_access_iterator<U> &rhs) const;

		template <typename U>
		bool operator!=(const random_access_iterator<U> &rhs) const;

		template <typename U>
		bool operator<(const random_access_iterator<U> &rhs) const;

		template <typename U>
		bool operator<=(const random_access_iterator<U> &rhs) const;

		template <typename U>
		bool operator>(const random_access_iterator<U> &rhs) const;

		template <typename U>
		bool operator>=(const random_access_iterator<U> &rhs) const;

		reference operator*() const;
		pointer operator->() const;
		reference operator[](difference_type n) const;

		random_access_iterator& operator++();
		random_access_iterator operator++(int);
		random_access_iterator& operator--();
		random_access_iterator operator--(int);

		random_access_iterator operator+(difference_type n) const;
		random_access_iterator operator-(difference_type n) const;

		difference_type operator-(const random_access_iterator &rhs) const;

		random_access_iterator& operator+=(difference_type n);
		random_access_iterator& operator-=(difference_type n);

		pointer base() const;

	private:
		pointer m_Current;
};

template <typename T>
ft::random_access_iterator<T> operator+(
	typename ft::random_access_iterator<T>::difference_type n,
	const ft::random_access_iterator<T> &rhs
);

#include "random_access_iterator_impl.hpp"
