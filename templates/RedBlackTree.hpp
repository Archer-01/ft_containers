#pragma once

#include "type_traits.hpp"
#include <cstddef>

namespace ft
{

	template<
		typename T,
		typename Compare,
		typename Allocator
	>
	class RedBlackTree
	{
		private:
			/**
			 * @defgroup Implementation related data structures
			 *
			 */
			enum NodeColor
			{
				RED,
				BLACK
			};

			enum NodeSide
			{
				LEFT,
				RIGHT
			};

			struct Node;

			/**
			 * @defgroup Attributes
			 *
			 */

			Node *m_Root;
			size_t m_Size;
			Allocator m_Allocator;
			Compare m_Compare;

		public:
			/**
			 * @defgroup Constructors
			 *
			 */

			RedBlackTree();
			explicit RedBlackTree(
				const Compare &comp,
				const Allocator &alloc = Allocator()
			);
			template <typename InputIterator>
			RedBlackTree(
				InputIterator first,
				typename ft::enable_if<
					not ft::is_integral<InputIterator>::value,
					InputIterator
				>::type last,
				const Compare &comp = Compare(),
				const Allocator &alloc = Allocator()
			);
			RedBlackTree(const RedBlackTree &other);

			/**
			 * @defgroup Destructor
			 *
			 */

			~RedBlackTree();

			/**
			 * @defgroup Assignment operator
			 *
			 */

			RedBlackTree &operator=(const RedBlackTree &other);

			/**
			 * @defgroup Insert method
			 *
			 */

			void insert(T value);
			void print() const;

		private:
			/**
			 * @defgroup Static methods
			 *
			 */

			static void RecursiveInsert(
				Node *root,
				Node *node,
				const Compare &comp
			);
			static void RecursivePrint(Node *root);
			static void RecursiveDelete(Node *root, Allocator &alloc);

			/**
			 * @defgroup Private methods
			 *
			 */

			Node *copyTree(Node *srcRoot);

			void leftRotate(Node *grandParent);
			void rightRotate(Node *grandParent);
			void leftRightRotate(Node *grandParent);
			void rightLeftRotate(Node *grandParent);

			void rotate(Node *problemNode);
			void simpleRotationRecolor(Node *problemNode);
			void doubleRotationRecolor(Node *problemNode);

			const Node *aunt(const Node *node) const;
			static Node *Sibling(Node *node);
	};

}; // namespace ft

#include "rbt_internals/RBTNode.hpp"
#include "rbt_internals/RBT_impl.hpp"
