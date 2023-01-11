#pragma once

#include "red_black_tree.hpp"

template <typename T, typename Compare, typename Allocator>
class ft::RedBlackTree
{
	public:
		/**
		 * @def Typedefs
		 *
		 */
		typedef T value_type;
		typedef Node<T, Allocator> node_type;
		typedef Compare value_compare;
		typedef Allocator allocator_type;

	private:
		/**
		 * @def Attributes
		 *
		 */
		node_type *root;
		value_compare compare;
		allocator_type allocator;

	public:
		/**
		 * @def Constructors
		 *
		 */
		RedBlackTree();

		explicit RedBlackTree(
			const value_compare &comp,
			const allocator_type &alloc
		);

		template <typename InputIterator>
		RedBlackTree(
			InputIterator first,
			InputIterator last,
			const value_compare &comp,
			const allocator_type &alloc
		);

		RedBlackTree(const RedBlackTree &rhs);

		/**
		 * @def Destructor
		 *
		 */
		~RedBlackTree();

		/**
		 * @def Assignment operator
		 *
		 */
		RedBlackTree &operator=(const RedBlackTree &rhs);

		/**
		 * @def Getters
		 *
		 */
		node_type *getRoot() const;
		allocator_type getAllocator() const;
		value_compare getCompare() const;

		/**
		 * @def Member functions
		 *
		 */
		void clear(node_type *root);
		void insert(const value_type &value);

	private:
		/**
		 * @def Private methods
		 *
		 */
		node_type *copyTree(node_type *srcRoot);
};

#include "red_black_tree_internals/RedBlackTree_impl.hpp"
