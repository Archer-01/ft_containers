#pragma once

#include "RedBlackTree.hpp"

template <typename T, typename Compare, typename Allocator>
template <typename NodeType, typename U>
class ft::RedBlackTree<T, Compare, Allocator>::Iterator
{
	private:
		/**
		 * @defgroup Typedefs
		 *
		 * - Pointer
		 * - Value type
		 * - Node pointer
		 *
		 */

		typedef U* pointer;
		typedef U value_type;
		typedef U& reference;
		typedef NodeType* node_pointer;

		/**
		 * @defgroup Attributes
		 *
		 * - m_Current: Pointer to the current node
		 * - m_Root: Pointer to the root node
		 *
		 */

		node_pointer m_Current;
		node_pointer m_Root;

		/**
		 * @defgroup Private methods
		 *
		 * - Leftmost node
		 * - Rightmost node
		 *
		 */

		node_pointer leftmostNode(node_pointer start) const;
		node_pointer rightmostNode(node_pointer start) const;

	public:
		/**
		 * @defgroup Constructors
		 *
		 * - Default constructor
		 * - Parametrized constructor
		 * - Copy constructor
		 *
		 */

		Iterator();
		Iterator(node_pointer root, node_pointer current);
		template <typename OtherNodeType, typename V>
		Iterator(const Iterator<OtherNodeType, V> &rhs);

		/**
		 * @defgroup Getters
		 *
		 * - Get current node
		 * - Get root node
		 *
		 */

		node_pointer getCurrent() const;
		node_pointer getRoot() const;

		/**
		 * @defgroup Operators
		 *
		 * - Assignment operator
		 * - Dereference operator *
		 * - Dereference operator ->
		 * - Pre-increment operator ++
		 * - Increment operator ++
		 * - Pre-decrement operator --
		 * - Decrement operator --
		 * - Equality operator ==
		 * - Inequality operator !=
		 *
		 */

		template <typename OtherNodeType, typename V>
		Iterator &operator=(const Iterator<OtherNodeType, V> &rhs);

		reference &operator*() const;
		pointer operator->() const;

		Iterator &operator++();
		Iterator operator++(int);

		Iterator &operator--();
		Iterator operator--(int);

		template <typename OtherNodeType, typename V>
		bool operator==(const Iterator<OtherNodeType, V> &rhs) const;
		template <typename OtherNodeType, typename V>
		bool operator!=(const Iterator<OtherNodeType, V> &rhs) const;
};

#include "RBTIterator_impl.hpp"
