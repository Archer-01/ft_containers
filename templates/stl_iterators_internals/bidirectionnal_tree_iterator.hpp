#pragma once

#include "stl_iterators.hpp"
#include "red_black_tree.hpp"

template <typename NodeType, typename T>
class ft::bidirectionnal_tree_iterator
	: public std::iterator<std::bidirectional_iterator_tag, T>
{
	private:
		/**
		 * @def Private typedefs
		 *
		 */
		typedef NodeType* node_pointer;

	public:
		/**
		 * @def Public Typedefs
		 *
		 */
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::bidirectional_iterator_tag iterator_category;

		/**
		 * @def Constructors
		 *
		 */
		bidirectionnal_tree_iterator();
		bidirectionnal_tree_iterator(node_pointer node, node_pointer root);

		template <typename OtherNodeType, typename U>
		bidirectionnal_tree_iterator(
			const bidirectionnal_tree_iterator<OtherNodeType, U> &rhs
		);

		/**
		 * @def Assignment operator
		 *
		 */
		template <typename OtherNodeType, typename U>
		bidirectionnal_tree_iterator &operator=(
			const bidirectionnal_tree_iterator<OtherNodeType, U> &rhs
		);

		/**
		 * @def Getters
		 *
		 */
		node_pointer getCurrent() const;
		node_pointer getRoot() const;

		/**
		 * @def Access operators
		 *
		 */
		reference operator*() const;
		pointer operator->() const;

		/**
		 * @def Relational operators
		 *
		 */
		template <typename OtherNode, typename U>
		bool operator==(const bidirectionnal_tree_iterator<OtherNode, U> &rhs) const;

		template <typename OtherNode, typename U>
		bool operator!=(const bidirectionnal_tree_iterator<OtherNode, U> &rhs) const;

		/**
		 * @def Increment & Decrement operators
		 *
		 */
		bidirectionnal_tree_iterator &operator++();
		bidirectionnal_tree_iterator operator++(int);
		bidirectionnal_tree_iterator &operator--();
		bidirectionnal_tree_iterator operator--(int);

	private:
		/**
		 * @def Attributes
		 *
		 */
		node_pointer current;
		node_pointer root;

		/**
		 * @def Private methods
		 *
		 */
		node_pointer leftmostNode(node_pointer node) const;
		node_pointer rightmostNode(node_pointer node) const;
};

#include "bidirectionnal_tree_iterator_impl.hpp"
