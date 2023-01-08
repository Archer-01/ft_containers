#pragma once

#include "type_traits.hpp"
#include "iterator.hpp"
#include "utility.hpp"
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

		public:
			struct Node;

		private:
			template <typename NodeType, typename U>
			class Iterator;

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
			 * @defgroup Typedefs
			 *
			 */

			typedef Iterator<Node, T> iterator;
			typedef Iterator<const Node, const T> const_iterator;

			/**
			 * @defgroup Constructors
			 *
			 */

			RedBlackTree(
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
			 * @defgroup Manipulation methods
			 *
			 * - Insert
			 * - Find
			 * - Erase
			 *
			 */

			ft::pair<iterator, bool> insert(const T &value);
			ft::pair<iterator, bool> insertAt(iterator position, const T &value);
			Node *find(const T &value);
			Node *findAt(iterator position, const T &value);
			void erase(iterator position);

			/**
			 * @def Print methods
			 *
			 */
			void print() const;
			void prettyPrint() const;

			/**
			 * @defgroup Getters
			 *
			 */

			Allocator get_allocator() const;
			Node *get_root() const;
			Compare get_compare() const;
			size_t get_size() const;

			/**
			 * @defgroup Iterators
			 *
			 */

			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;

		private:
			/**
			 * @defgroup Static methods
			 *
			 * - Recursive insert
			 * - Recursive print
			 * - Recursive delete
			 * - Recursive pretty print
			 *
			 */

			static void RecursiveInsert(
				Node *root,
				Node *node,
				const Compare &comp
			);
			static void RecursivePrint(Node *root);
			static void RecursiveDelete(Node *root, Allocator &alloc);
			static void RecursivePrettyPrint(Node *node, int indent);

			/**
			 * @defgroup Private methods
			 *
			 * - Copy tree
			 *
			 * - Left rotate
			 * - Right rotate
			 * - Left right rotate
			 * - Right left rotate
			 * - Insert fixup rotate
			 * - Simple rotation recolor
			 * - Double rotation recolor
			 * - Insert fixup recolor
			 *
			 * - Erase (Node pointer overload)
			 * - Transplant
			 * - Erase fixup
			 *
			 */

			Node *copyTree(Node *srcRoot);

			void insertionFixup(Node *problemNode);
			void leftRotate(Node *grandParent);
			void rightRotate(Node *grandParent);
			void leftRightRotate(Node *grandParent);
			void rightLeftRotate(Node *grandParent);
			void insertionFixupRotate(Node *problemNode);
			void simpleRotationRecolor(Node *problemNode);
			void doubleRotationRecolor(Node *problemNode);
			void recolor(Node *problemNode);

			void erase(Node *nodeToErase);
			void transplant(const Node *nodeToErase, Node *replacement);
			void eraseFixup(Node *fixupNode, NodeSide fixupSide);
	};

}; // namespace ft

#include "rbt_internals/RBTIterator.hpp"
#include "rbt_internals/RBTNode.hpp"
#include "rbt_internals/RBT_impl.hpp"
