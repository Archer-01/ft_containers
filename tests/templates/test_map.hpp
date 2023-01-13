#pragma once

#include "map.hpp"
#include <cassert>
#include <functional>
#include <memory>

template <
	template <typename T1, typename T2> class Pair,
	template <
		typename Key,
		typename T,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator<Pair<const Key, T> >
	> class Map
>
void test_map(Pair<int, int> (*make_pair)(int, int))
{
	Pair<int, int> arr[5] = {
		make_pair(1, -1),
		make_pair(2, -2),
		make_pair(3, -3),
		make_pair(4, -4),
		make_pair(5, -5),
	};

	{
		Map<int, int> map1;
		Map<int, int> map2(&arr[0], &arr[5]);

		{
			Map<int, int> map3 = map2;

			assert(map3.size() == 5);
			assert(map3 == map2);
		}

		assert(map1.empty() == true);
		assert(map2.size() == 5);
	}
	{
		Map<int, int> map(&arr[0], &arr[5]);

		assert(map[1] == -1);
		assert(map[0] == 0);
		assert(map.at(2) == -2);
	}
	{
		Map<int, int> map(&arr[0], &arr[5]);

		typename Map<int, int>::iterator iter = map.begin();

		while (iter != map.end())
		{
			assert(iter->first == -iter->second);
			++iter;
		}
	}
	{
		Map<int, int> map(&arr[0], &arr[5]);
		
		typename Map<int, int>::reverse_iterator iter = map.rbegin();

		while (iter != map.rend())
		{
			assert(iter->first == -iter->second);
			++iter;
		}
	}
	{
		Map<int, int> map;

		map.insert(&arr[0], &arr[5]);
		map.clear();

		assert(map.empty() == true);

		map.insert(make_pair(42, -42));

		assert(map.size() == 1);
		assert(map[42] == -42);

		map.erase(map.begin());

		assert(map.empty() == true);
	}
	{
		Map<int, int> map;

		map.insert(&arr[0], &arr[5]);

		assert(map.find(42) == map.end());

		map.erase(map.begin(), map.end());

		assert(map.empty() == true);
	}
}
