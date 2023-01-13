#pragma once

#include "red_black_tree.hpp"
#include "iterator.hpp"
#include "stl_iterators.hpp"
#include <functional>
#include <memory>

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
	};

}; // namespace ft
