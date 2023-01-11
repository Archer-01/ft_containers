#pragma once

#include "red_black_tree.hpp"
#include <iomanip>
#include <iostream>

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

		/**
		 * @def Print method
		 *
		 */
		void print() const;

	private:
		/**
		 * @def Private helper methods
		 *
		 */
		node_type *copyTree(node_type *srcRoot);

		void insertFixup(node_type *problemNode);
		void colorFlip(node_type *problemNode);
		void rotation(node_type *problemNode);
		void leftRotation(node_type *grandParent);
		void rightRotation(node_type *grandParent);

		static void Print(node_type *node, int indent);
};

#include "red_black_tree_internals/RedBlackTree_impl.hpp"
