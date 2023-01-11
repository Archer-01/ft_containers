#pragma once

#include "red_black_tree.hpp"
#include "iterator.hpp"
#include "stl_iterators.hpp"
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
			 * @def Member classes
			 *
			 */
			class value_compare;

		private:
			/**
			 * @def Private typedefs
			 *
			 */
			typedef Node<ft::pair<const Key, T>, Allocator> node_type;

		public:
			/**
			 * @def Public typedefs
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
			typedef ft::bidirectionnal_tree_iterator<node_type, value_type> iterator;
			typedef ft::bidirectionnal_tree_iterator<const node_type, const value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			/**
			 * @def Constructors
			 *
			 */
			map();

			explicit map(
				const Compare &comp,
				const Allocator &alloc = Allocator()
			);

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
			 * @def Assignment operator
			 *
			 */
			map &operator=(const map &other);

			/**
			 * @def Get Allocator
			 *
			 */
			allocator_type get_allocator() const;

			/**
			 * @def Element access
			 *
			 */
			T &at(const Key &key);
			const T &at(const Key &key) const;

			T& operator[](const Key &key);

		private:
			/**
			 * @def Private typedefs
			 *
			 */
			typedef ft::RedBlackTree<value_type, value_compare, allocator_type> tree_type;

			/**
			 * @def Attributes
			 *
			 */
			tree_type tree;

	};

}; // namespace ft

#include "map_internals/map_impl.hpp"
#include "map_internals/value_compare.hpp"
