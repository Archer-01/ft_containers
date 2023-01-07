#pragma once

#include "map.hpp"
#include <functional>

template <typename Key, typename T, typename Compare, typename Allocator>
class ft::map<Key, T, Compare, Allocator>::value_compare
	: public std::binary_function<value_type, value_type, bool>
{
	friend class map;

	protected:
		Compare comp;

		value_compare(Compare c)
		{
			this->comp = c;
		}

	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;

		bool operator()(const value_type &lhs, const value_type &rhs) const
		{
			return comp(lhs.first, rhs.first);
		}
};
