#pragma once

#include "set.hpp"
#include <cassert>
#include <functional>
#include <memory>
#include <set>

template <
	template <
		typename Key,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator<Key>
	> class Set
>
void test_set()
{
	const int arr[5] = {1, 2, 3, 4, 5};

	{
		Set<int> set1;
		Set<int> set2(&arr[0], &arr[5]);

		{
			Set<int> set3 = set2;

			assert(set3.size() == 5);
			assert(set3 == set2);
		}

		assert(set1.empty());
		assert(set2.size() == 5);
	}
	{
		Set<int> set(&arr[0], &arr[5]);

		typename Set<int>::const_iterator it = set.begin();
		int num = 1;

		while (it != set.end())
		{
			assert(*it == num);
			++num;
			++it;
		}

		typename Set<int>::const_reverse_iterator riter = set.rbegin();

		num = 5;
		while (riter != set.rend())
		{
			assert(*riter == num);
			--num;
			++riter;
		}
	}
	{
		Set<int> set;

		set.insert(&arr[0], &arr[5]);

		assert(set.size() == 5);
		assert(set.count(1) == 1);
		assert(set.find(42) == set.end());

		set.erase(set.begin());

		assert(set.size() == 4);
		assert(*set.begin() == 2);

		set.erase(set.begin(), set.end());

		assert(set.empty() == true);
	}
}
