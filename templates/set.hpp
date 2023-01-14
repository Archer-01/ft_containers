#pragma once

#include "algorithm.hpp"
#include "iterator.hpp"
#include "red_black_tree.hpp"
#include "stl_iterators.hpp"
#include <functional>
#include <memory>
#include <stdexcept>

namespace ft
{

	template<
		typename Key,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator<Key>
	>
	class set
	{
		private:
			/**
			 * @def Private typedefs
			 *
			 */
			typedef Node<Key, Allocator> node_type;

		public:
			/**
			 * @def Typedefs
			 *
			 */
			typedef Key key_type;
			typedef Key value_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef Compare key_compare;
			typedef Compare value_compare;
			typedef Allocator allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef typename ft::bidirectionnal_tree_iterator<node_type, value_type> iterator;
			typedef typename ft::bidirectionnal_tree_iterator<const node_type, const value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			/**
			 * @def Constructors
			 *
			 */
			set();

			explicit set(
				const key_compare &comp,
				const allocator_type &alloc = Allocator()
			);

			template <typename InputIterator>
			set(
				InputIterator first,
				InputIterator last,
				const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type()
			);

			set(const set &other);

			/**
			 * @def Destructor
			 *
			 */
			~set();

			/**
			 * @def Assignment operator
			 *
			 */
			set &operator=(const set &other);

			/**
			 * @def Get allocator
			 *
			 */
			allocator_type get_allocator() const;

			/**
			 * @def Iterators
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
			 * @def Capacity
			 *
			 */
			bool empty() const;
			size_type size() const;
			size_type max_size() const;

			/**
			 * @def Modifiers
			 *
			 */
			void clear();

			ft::pair<iterator, bool> insert(const value_type &value);

			iterator insert(iterator position, const value_type &value);

			template <typename InputIterator>
			void insert(InputIterator first, InputIterator last);

			void erase(iterator position);
			void erase(iterator first, iterator last);
			size_type erase(const key_type &key);

			void swap(set &other);

			/**
			 * @def Lookup
			 *
			 */
			size_type count(const key_type &key) const;

			iterator find(const key_type &key);
			const_iterator find(const key_type &key) const;

			iterator lower_bound(const key_type &key);
			const_iterator lower_bound(const key_type &key) const;

			iterator upper_bound(const key_type &key);
			const_iterator upper_bound(const key_type &key) const;

			ft::pair<iterator, iterator> equal_range(const key_type &key);
			ft::pair<const_iterator, const_iterator> equal_range(
				const key_type &key
			) const;

			/**
			 * @def Observers
			 *
			 */
			key_compare key_comp() const;
			value_compare value_comp() const;

		private:
			/**
			 * @def Private typedefs
			 *
			 */
			typedef ft::RedBlackTree<value_type, key_compare, allocator_type> tree_type;

			/**
			 * @def Attributes
			 *
			 */
			tree_type _tree;
			size_type _size;
	};

	/**
	 * @def Relationnal operators (Non-member function)
	 *
	 */
	template <typename Key, typename Compare, typename Allocator>
	bool operator==(
		const set<Key, Compare, Allocator> &lhs,
		const set<Key, Compare, Allocator> &rhs
	);

	template <typename Key, typename Compare, typename Allocator>
	bool operator!=(
		const set<Key, Compare, Allocator> &lhs,
		const set<Key, Compare, Allocator> &rhs
	);

	template <typename Key, typename Compare, typename Allocator>
	bool operator<(
		const set<Key, Compare, Allocator> &lhs,
		const set<Key, Compare, Allocator> &rhs
	);

	template <typename Key, typename Compare, typename Allocator>
	bool operator<=(
		const set<Key, Compare, Allocator> &lhs,
		const set<Key, Compare, Allocator> &rhs
	);

	template <typename Key, typename Compare, typename Allocator>
	bool operator>(
		const set<Key, Compare, Allocator> &lhs,
		const set<Key, Compare, Allocator> &rhs
	);

	template <typename Key, typename Compare, typename Allocator>
	bool operator>=(
		const set<Key, Compare, Allocator> &lhs,
		const set<Key, Compare, Allocator> &rhs
	);

	/**
	 * @def Swap (Non-member function)
	 *
	 */
	template <typename Key, typename Compare, typename Allocator>
	void swap(
		ft::set<Key, Compare, Allocator> &lhs,
		ft::set<Key, Compare, Allocator> &rhs
	);

}; // namespace ft

#include "set_internals/set_impl.hpp"
