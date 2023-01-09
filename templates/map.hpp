#pragma once

#include "RedBlackTree.hpp"
#include "type_traits.hpp"
#include "utility.hpp"
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>

namespace ft
{
	template <
		typename Key,
		typename T,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator<ft::pair<const Key, T> >
	>
	class map
	{
		public:
			/**
			 * @def value_compare functor
			 *
			 */

			class value_compare;

			/**
			 * @defgroup Typedefs
			 *
			 */

			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<const Key, T> value_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef Compare key_compare;
			typedef Allocator allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef typename RedBlackTree<value_type, value_compare, allocator_type>::iterator iterator;
			typedef typename RedBlackTree<value_type, value_compare, allocator_type>::const_iterator const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		private:
			typedef ft::RedBlackTree<value_type, value_compare, allocator_type> tree_type;

		public:
			/**
			 * @defgroup Constructors
			 *
			 * - Default constructor
			 * - Parametric constructor (Compare & Allocator)
			 * - Range constructor
			 * - Copy constructor
			 *
			 */

			map();
			explicit map(const Compare &comp, const Allocator &alloc = Allocator());
			template <typename InputIterator>
			map(
				InputIterator first,
				InputIterator last,
				const Compare &comp = Compare(),
				const Allocator &alloc = Allocator()
			);
			map(const map &other);

			/**
			 * @def Destructor
			 *
			 */

			~map();

			/**
			 * @defgroup Assignment operator
			 *
			 */

			map &operator=(const map &other);

			/**
			 * @def Get allocator
			 *
			 */

			allocator_type get_allocator() const;

			/**
			 * @defgroup Element access
			 *
			 */

			T& at(const Key &key);
			T& operator[](const Key &key);

			/**
			 * @defgroup Iterators
			 *
			 */

			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;

			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;

			/**
			 * @defgroup Capacity
			 *
			 */

			bool empty() const;
			size_type size() const;
			size_type max_size() const;

			/**
			 * @defgroup Modifiers
			 *
			 */

			void clear();
			ft::pair<iterator, bool> insert(const value_type &value);
			iterator insert(iterator pos, const value_type &value);
			template <typename InputIterator>
			void insert(InputIterator first, InputIterator last);

			void erase(iterator pos);
			void erase(iterator first, iterator last);
			size_type erase(const Key &key);

			void swap(map &other);

			/**
			 * @defgroup Lookup
			 *
			 */

			size_type count(const Key &key) const;

			iterator find(const Key &key);
			const_iterator find(const Key &key) const;

			iterator lower_bound(const Key &key);
			const_iterator lower_bound(const Key &key) const;

			iterator upper_bound(const Key &key);
			const_iterator upper_bound(const Key &key) const;

			ft::pair<iterator, iterator> equal_range(const Key &key);
			ft::pair<const_iterator, const_iterator> equal_range(
				const Key &key
			) const;

		private:
			tree_type m_Tree;
	};
}; // namespace ft

#include "map_internals/map_impl.hpp"
#include "map_internals/value_compare.hpp"
