#pragma once

#include "../map.hpp"
#include <functional>

template <typename Key, typename T, typename Compare, typename Allocator>
class ft::map<Key, T, Compare, Allocator>::value_compare
	: public std::binary_function<value_type, value_type, bool>
{
	friend class map;

	protected:
		/**
		 * @def Attributes
		 *
		 */
		Compare comp;

		/**
		 * @def Constructors
		 *
		 */
		value_compare(Compare comp) : comp(comp) {}

	public:
		/**
		 * @def Typedefs
		 *
		 */
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;

		/**
		 * @def Operators
		 *
		 */
		bool operator()(const value_type &lhs, const value_type &rhs) const
		{
			return comp(lhs.first, rhs.first);
		}
};
